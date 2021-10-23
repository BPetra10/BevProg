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

int main()
{
	Month m = Month::jan;
	++m;

	cout<<m<<"\n";

	return 0;
}