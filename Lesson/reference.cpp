#include "../header.h"

int main()
{
	//i r és cr ugyanaz az objektum, más névvel
	int i = 7;
	coout<<i<<"\n";

	int&r = i; //r az referencia i-re
	r=9;
	cout<<"i: "<<i<<"\n";
	cout<<"r: "<<r<<"\n";

	//konstans referencia:
	const int&cr = i; // a cr csak readonly, értéke nem módosítható
	cout<<"i: "<<i<<"\n";
	cout<<"r: "<<r<<"\n";
	cout<<"cr: "<<cr<<"\n";

	i=100;
	cout<<"i: "<<i<<"\n";
	cout<<"r: "<<r<<"\n";
	cout<<"cr: "<<cr<<"\n";

	return 0;
}