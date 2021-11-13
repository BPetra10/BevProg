#include "../header.h"

int main()
{
	double* a = new double;
	double* b = new double[5];
	std::cout<<"a=="<<a<<" *a=="<<*a<<"\n";
	std::cout<<"b=="<<b<<" *b=="<<*b<<"\n";
	
	double* c = new double[4];
	for (int i = 0; i < 4; ++i)
		cout<<c[i]<<" ";
	cout<<"\n";

	int* d2 = new int[4];
	cout<<d2[2]<<"\n";

	double* e = new double[4]{1.1,2.2,3.3,4.4};
	for (int i = 0; i < 4; ++i)
		cout<<e[i]<<" ";
	cout<<"\n";

	delete a;
	delete b;
	delete[] c;
	delete[] d2;
	delete[] e;
	
	return 0;
}