#include "../header.h"

class Date{
private:
 int year,month,day;
public:
 Date(int year, int month, int day);
 void add_day(int n);
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

Date::Date(int y, int m, int d)
{
	if(y>0)
		year=y;
	else
		error("Invalid year.\n");

	if(m<=12 && m>0)
		month=m;
	else
		error("Invalid month.\n");

	if(d<=31 && d>0)
		day=d;
	else
		error("Invalid day.\n");
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
}catch(exception& e){
	cerr <<e.what()<<"\n";
		return 1;
}