#include "../header.h"

int ga[100];
int main()
{
	char lac[100];
	int lai[100];
	double lad[100];

	lad[7]=100;

	cout<<lad[7]<<"\n";
	for (int i = 0; i < 100; ++i)
		lad[i]=i;

	for (int i = 0; i < 100; ++i)
		cout<<lad[i]<<"\n";

	double* p = &lad[5]; 
	cout<<*p<<"\n";

	//access
	cout<< p[2]<<"\n"; //p pointerhez képest kettővel arrébb lévő elem értéke
	cout<< p[-3]<<"\n"; //3-mal előtte lévő érték

	p+=2; //p pointer elléptetése 2-vel 
	cout<<*p<<"\n";

	for (double* k = &lad[0]; k< &lad[100];k++)
		cout<<*k<<' ';
	cout<<"\n";
	
	return 0;
}