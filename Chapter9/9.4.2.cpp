#include "../header.h"

struct Date 
{
	int y, m, d;
	Date(int y, int m, int d);
	void add_day(int n);
};

Date::Date(int year, int month, int day)
{
	if(year>0)
		y=year;
	else
		error("Invalid year.");

	if(month<=12 && month>0)
		m=month;
	else
		error("Invalid month.");

	if(day<=31 && day>0)
		d=day;
	else
		error("Invalid day.");
}

void Date::add_day(int n)
{
	d+=n;
	if(d>31)
	{
		m++;
		d-=31;
	}
	if(m>12)
	{
		y++;
		m-=12;
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y<< ',' << d.m<< ',' << d.d << ')';
}

int main()
try
{
	//Date my_birthday; 
	//Date today {12,24,2007};
	//Date invalid {2004,13,-5};
    //cout<<invalid<<"\n";
	Date today {1978, 6, 25};
	Date tomorrow=today;
	tomorrow.add_day(1);
	cout<<"Today: "<< today<<"\n"<<"Tomorrow: "<<tomorrow<<"\n";
	Date last {2000,12,31};
	Date next = {2014,2,14};
	Date christmas = Date{1976,12,24};
	cout<<"last: "<<last<<"\n"<<"next: "<<next<<"\n"<<"christmas: "<<christmas<<"\n";
	last.add_day(1);
	//add_day(2);
	cout<<"last.add_day(1): "<< last<<"\n";
  
	return 0;
}
catch(exception& e)
{
	cerr <<e.what()<<"\n";
	return 1;
}
