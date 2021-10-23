#include "../header.h"

struct Date{
 int y,m,d;	
};

void intit_date(Date& date, int y, int m, int d)
{
	if(y>0)
		date.y=y;
	else
		error("Invalid year.\n");

	if(m<=12 && m>0)
		date.m=m;
	else
		error("Invalid month.\n");

	if(d<=31 && d>0)
		date.d=d;
	else
		error("Invalid day.\n");
}

void add_day(Date& date, int n)
{
	date.d+=n;
	if(date.d>31)
	{
		date.m++;
		date.d-=31;
	}
	if(date.m>12)
	{
		date.y++;
		date.m-=12;
	}
}

int main()
try{
	Date today;
	today.y = 2021;
	today.m = 10;
	today.d = 23;

	cout<<"Date: "<<today.y<<"."<<today.m<<"."<<today.d<<".\n";

	Date tomorrow;
	intit_date(tomorrow,2021,10,24);
	cout<<"Tomorrow: "<<tomorrow.y<<"."<<tomorrow.m<<"."<<tomorrow.d<<".\n";

	add_day(tomorrow,4);
	cout<<"Add day: "<<tomorrow.y<<"."<<tomorrow.m<<"."<<tomorrow.d<<".\n";

	return 0;
}catch(exception& e){
	cerr <<e.what()<<"\n";
		return 1;
}