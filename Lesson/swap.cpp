#include "../header.h"

void swap(double& d1, double& d2)
{
	double temp=d1;
	d1=d2;
	d2=temp;
}

int main(){
	double x1=2.3;
	double x2=3.4;

	cout<<"x1: "<<x1<<" x2: "<<x2<<"\n"; //x1=d1 x2=d2
	swap(x1,x2);
	cout<<"x1: "<<x1<<" x2: "<<x2<<"\n";
	return 0;
}