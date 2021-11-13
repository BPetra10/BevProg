#include "../header.h"

int main()
{
	int var=17;
	int* ptr = &var; //A var objektum memóriacímét kérjük el

	int x = 42;
	int* ptr2 = &x;

	double d = 3.14;
	double* dptr = &d;

	cout<<"ptr=="<<ptr<<" *ptr=="<<*ptr<<"\n";
	cout<<"ptr2=="<<ptr2<<" *ptr2=="<<*ptr2<<"\n";
	cout<<"dptr=="<<dptr<<" *dptr=="<<*dptr<<"\n";

	*ptr=27;
	*dptr=2.5;
	*ptr2=237;

	cout<<"\n";
	cout<<"ptr=="<<ptr<<" *ptr=="<<*ptr<<"\n";
	cout<<"ptr2=="<<ptr2<<" *ptr2=="<<*ptr2<<"\n";
	cout<<"dptr=="<<dptr<<" *dptr=="<<*dptr<<"\n";

	*ptr = *ptr2;
	

	return 0;
}