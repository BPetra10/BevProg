#include "../header.h"

namespace UDChrono{
class Year{
	static constexpr int min=1800;
	static constexpr int max=2200;
public:
	class Invalid{};
	Year(int x):y{x}{if(x<min || x>max)throw Invalid{};}
	int year(){return y;}
	void increment(){y++;}
private:
	int y;
};

Year operator++(Year& year){
	year.increment();
	return year;
}

ostream& operator<<(ostream& os, Year year){
	return os << year.year();
}

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
 Year year;
 Month month;
 int day;
public:
 class Invalid{};
 Date():year(Year{2001}),month(Month::jan),day(1){}
 Date(Year y, Month m, int d): year(y),month(m),day(d){if(!is_valid()) throw Invalid();};
 void add_day(int n);
 bool is_valid();
 //Azért van const, mert ezek nem módosítják az objektumot, csak visszaadják
 Year get_year() const {return year;}; 
 Month get_month() const {return month;};
 int get_day() const {return day;};
 
 void set_year(Year y)
 {
 	 year=y;
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
	if(day<1 || day>31) return false;

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
		++year;
	}
}
}
//end namespace

ostream& operator<<(ostream& os, const UDChrono::Date& d)
{
	return os<<d.get_year()<<". "<<d.get_month()<<" "<<d.get_day()<<".";
}

istream& operator>>(istream& is,UDChrono::Date& dd)
{
	int y,m,d;
	char ch1,ch2;
	is >> y >> ch1 >> m >> ch2 >> d;
	if (!is) return is;
	if(ch1!='.' || ch2!='.')
	{
		is.clear(ios_base::failbit);
		return is;
	}

	dd=UDChrono::Date{UDChrono::Year{y},UDChrono::Month(m-1),d};

	return is;
}

int main()
try{
	UDChrono::Date today{UDChrono::Year{2021},UDChrono::Month::aug,23};

	cout<<"Date: "<<today<<"\n";

	vector<UDChrono::Date> dates={
		UDChrono::Date{UDChrono::Year{2021},UDChrono::Month::aug,24},
		UDChrono::Date{UDChrono::Year{2021},UDChrono::Month::feb,1},
		UDChrono::Date{UDChrono::Year{2021},UDChrono::Month::jan,20},
		UDChrono::Date{UDChrono::Year{2021},UDChrono::Month::jan,25}
	};

	for(const auto& date: dates)
		cout<<"Date: "<<date<<".\n";

	UDChrono::Date tomorrow;

	cout<<"Give a YYYY.MM.DD format \n";
	cin>>tomorrow;

	cout<<"Tomorrow's date: "<<tomorrow<<"\n";

	return 0;

}catch(UDChrono::Year::Invalid){
	cerr <<"Invalid year."<<"\n";
		return 1;
}catch(UDChrono::Date::Invalid){
	cerr <<"Invalid date."<<"\n";
		return 2;
}
catch(exception& e){
	cerr <<e.what()<<"\n";
		return 3;
}