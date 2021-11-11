#include "../header.h"

class Year 
{
    static const int min = 1800;
    static const int max = 2200;
    public:
        class Invalid { };
        Year(int x) : y{x} { if (x<min || max<=x) throw Invalid{}; }
        int year() { return y; }
        void increment(){y++;}
    private:
        int y;
};

Year operator++(Year& y)
{
    y.increment();
    return y;
}

ostream& operator<<(ostream& os, Year y){
    return os << y.year();
}

enum class Month 
{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> month_tbl =
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

Month operator++(Month& m)
{
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
    return m;
}

ostream& operator<<(ostream& os, Month m)
{
    return os << month_tbl[int(m)];
}

class Date
{
    public:
        class Invalid{};
        Date(Year y, Month m, int d);
        void add_day(int n);
        bool is_valid();
        Year year() {return y;};
        Month month() {return m;};
        int day() {return d;};
    private:
        Year y;
        Month m;
        int d;  
};

Date::Date(Year yy, Month mm, int dd)
    : y(yy), m(mm), d(dd)
{
    if (!is_valid()) throw Invalid{};
}

bool Date::is_valid(){
    if(d<1 || d>31) return false;

    return true;
}

void Date::add_day(int n)
{
    d+=n;
    if(d>31)
    {
        ++m;
        d-=31;
    }
    if(m==Month::jan)
    {
        ++y;
    }
}

ostream& operator<<(ostream& os,Date& d)
{
    return os << '(' << d.year()<< ',' << d.month()<< ',' << d.day() << ')';
}


int main()
try
{
    Date today {Year{1978},Month::jun, 25};
    Date tomorrow=today;
    tomorrow.add_day(1);
    cout<<"Today: "<< today<<"\n"<<"Tomorrow: "<<tomorrow<<"\n";

    //Date invalid {Year{2004},Month::asd,-5};
    //cout<<invalid<<"\n";
  
    return 0;
}catch(Year::Invalid){
    cerr <<"Invalid year."<<"\n";
        return 1;
}catch(Date::Invalid){
    cerr <<"Invalid date."<<"\n";
        return 2;
}
catch(exception& e)
{
    cerr <<e.what()<<"\n";
    return 3;
}