#include "../header.h"

int main()
{
	double cm_per_inch = 2.54;
	double length = 1;
	while(length!=0)
	{
		cout << "Please enter a value in inch: ";
		cin>> length;
		cout << "length in cm: "<<length * cm_per_inch << "\n";
	}
	return 0;
}
