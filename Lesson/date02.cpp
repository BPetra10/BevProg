#include "../header.h"

struct Date{
 int year,month,day;
 Date(int year, int month, int day);
 void add_day(int n);
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

	cout<<"Date: "<<today.year<<". "<<today.month<<". "<<today.day<<".\n";

	return 0;
}catch(exception& e){
	cerr <<e.what()<<"\n";
		return 1;
}