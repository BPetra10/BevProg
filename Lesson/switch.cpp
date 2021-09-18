#include "../header.h"

int main()
{
	constexpr double cm_per_inch = 2.54; //konstans megadás

	double length = -1;
	char unit = 0;

	cout << "Please enter a value in cm or in (c/i):\n";
	cin >> length >> unit;
	
	/*
	if (unit=='i')
		cout << "length is "<<length*cm_per_inch<<"\n";
	else if(unit=='c')
		cout << "length is "<<length/cm_per_inch<<"\n";
	else
		cout << "Unsopported unit.\n";
	*/

	switch(unit)
	{
		case 'i':
			cout << "length is "<<length*cm_per_inch<<"\n";
			break;
		case 'c':
			cout << "length is "<<length/cm_per_inch<<"\n";
			break;
		default:
			cout << "Unsopported unit.\n";
			break;
	}
	return 0;
}