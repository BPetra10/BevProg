#include "../header.h"

void print_array(const double p[], int n)
{
	for (int i = 0; i < n; ++i)
		cout<<p[i]<<" ";
	cout<<"\n";
}

int main()
{
	double lad[100];

	for (int i = 0; i < 100; ++i)
		lad[i]=i;

	print_array(lad,100);
	
	return 0;
}