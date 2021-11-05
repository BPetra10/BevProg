#include "../header.h"

class Date
{
    private:
        int y,m,d;
    public:
        Date(int y, int m, int d);
        void add_day(int n);
        int year(){return y;};
        int month(){return m;};
        int day(){return d;};
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

ostream& operator<<(ostream& os,Date& d)
{
    return os << '(' << d.year()<< ',' << d.month()<< ',' << d.day() << ')';
}

int main()
try
{
    Date today {1978, 6, 25};
    Date tomorrow=today;
    tomorrow.add_day(1);
    cout<<"Today: "<< today<<"\n"<<"Tomorrow: "<<tomorrow<<"\n";

    Date birthday {1970, 12, 30};
    cout <<"birthday: "<< birthday<< '\n';
    //birthday.m = 14;
    cout <<"birthday.month(): "<< birthday.month() << '\n';

    //Date invalid {2004,13,-5};
    //cout<<invalid<<"\n";
  
    return 0;
}
catch(exception& e)
{
    cerr <<e.what()<<"\n";
    return 1;
}