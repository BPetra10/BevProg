#include "../header.h"

struct Date 
{
	int y;
	int m;
	int d;
};

void init_day(Date& dd, int y, int m, int d)
{
	if(y>0)
		dd.y=y;
	else
		error("Invalid year.");

	if(m<=12 && m>0)
		dd.m=m;
	else
		error("Invalid month.");

	if(d<=31 && d>0)
		dd.d=d;
	else
		error("Invalid day.");
}

void add_day(Date& dd, int n)
{
	dd.d+=n;
	if(dd.d>31)
	{
		dd.m++;
		dd.d-=31;
	}
	if(dd.m>12)
	{
		dd.y++;
		dd.m-=12;
	}

	/*int newDateInDays=dd.y*365+dd.m*31+dd.d+n;
	int newDateYears=floor(newDateInDays/365);
	int dateLeft=newDateInDays-newDateYears*365;
	if(dateLeft==0)
	{
		dd.y+=newDateYears;
		dd.m=1;
		dd.d=1;
	}
	int newDateMonths=floor(dateLeft/31);
	int week = floor((dateLeft-newDateMonths*31)/7);
	int newDateDays=0;
	if(dateLeft-newDateMonths*31==0)
	{
		newDateMonths-=1;
		newDateDays=31;
	}
	newDateDays=(dateLeft-newDateMonths*31);

	dd.y=newDateYears;
	dd.m=newDateMonths;
	dd.d=newDateDays;*/
}

ostream& operator<<(ostream& os, const Date& d)
{
return os << '(' << d.y<< ',' << d.m<< ',' << d.d << ')';
}

void f()
{
	Date today;
	init_day(today, 1978, 6, 25);
	Date tomorrow=today;
	add_day(tomorrow,1);
	cout<<"Today: "<< today<<"\n"<<"Tomorrow: "<<tomorrow<<"\n";
	//Date invalid;
	//init_day(invalid,2004,13,-5);
}

int main()
try
{
	f();
	return 0;
}
catch(exception& e)
{
	cerr <<e.what()<<"\n";
	return 1;
}

