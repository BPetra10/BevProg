#include "../header.h"

const vector<string> months =
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

enum class Month
{
	jan,feb,apr,may,jun,jul,aug,sept,oct,nov,dec
};

Month operator++(Month& m){
 m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
 return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}

class Date{
private:
 int year;
 Month month;
 int day;
public:
 class Invalid{};
 Date(int y, Month m, int d): year(y),month(m),day(d){if(!is_valid()) throw Invalid();};
 void add_day(int n);
 bool is_valid();
 int get_year(){return year;};
 Month get_month(){return month;};
 int get_day(){return day;};
 
 void set_year(int y)
 {
 	if(y>0)
 	 year=y;
 	else
 		error("Invalid year.\n");
 }
 void set_month(Month m)
 {
 	 month=m;
 }
 void set_day(int d)
 {
 	if(d>0 && d<=31)
 	 day=d;
 	else
 		error("Invalid day.\n");
 }
};

bool Date::is_valid(){
	if(year<1 || day<1 || day>31) return false;

	return true;
}

void Date::add_day(int n)
{
	day+=n;
	if(day>31)
	{
		++month;
		day-=31;
	}
	if(month==Month::jan)
	{
		year++;
	}
}

int main()
try{
	Date today{2021,Month::aug,23};

	cout<<"Date: "<<today.get_year()<<". "<<today.get_month()<<" "<<today.get_day()<<".\n";

	Date my_birthday {2020,Month::dec,31};
	cout<<"Date: "<<my_birthday.get_year()<<". "<<my_birthday.get_month()<<" "<<my_birthday.get_day()<<".\n";

	return 0;
}catch(Date::Invalid){
	cerr <<"Invalid date."<<"\n";
		return 1;
}
catch(exception& e){
	cerr <<e.what()<<"\n";
		return 2;
}