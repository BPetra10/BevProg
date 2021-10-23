#include "../header.h"

class Date{
private:
 int year,month,day;
public:
 class Invalid{};
 Date(int y, int m, int d): year(y),month(m),day(d){if(!is_valid()) throw Invalid();};
 void add_day(int n);
 bool is_valid();
 int get_year(){return year;};
 int get_month(){return month;};
 int get_day(){return day;};
 void set_year(int y)
 {
 	if(y>0)
 	 year=y;
 	else
 		error("Invalid year.\n");
 }
 void set_month(int m)
 {
 	if(m>0 && m<=12)
 	 month=m;
 	else
 		error("Invalid month.\n");
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
	if(month<1 || month>12 || year<1 || day<1 || day>31) return false;

	return true;
}

void Date::add_day(int n)
{
	day+=n;
	if(day>31)
	{
		month++;
		day-=31;
	}
	if(month>12)
	{
		year++;
		month-=12;
	}
}

int main()
try{
	Date today{2021,10,23};

	cout<<"Date: "<<today.get_year()<<". "<<today.get_month()<<". "<<today.get_day()<<".\n";

	today.set_year(2222);
	today.set_month(12);
	today.set_day(31);
	
	cout<<"Date: "<<today.get_year()<<". "<<today.get_month()<<". "<<today.get_day()<<".\n";

	return 0;
}catch(Date::Invalid){
	cerr <<"Invalid date."<<"\n";
		return 1;
}
catch(exception& e){
	cerr <<e.what()<<"\n";
		return 2;
}