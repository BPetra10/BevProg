#include "../header.h"
int ga [10]={1,2,4,8,16,32,64,128,256,512};

void f(int name[], int elements)
{
	int la[10];
	for (int i = 0; i < elements; i++)
		la[i]=ga[i];
		
	for (int i = 0; i < elements; i++)
		cout<<la[i]<<" ";
		cout<<"\n";
		
	int* p = new int[elements];
	for (int i = 0; i < elements; i++)
		p[i]=name[i];
	
	for (int i = 0; i < elements; i++)
		cout<<p[i]<<" ";
		cout<<"\n";
		
	delete[] p;
}

int main()
{
	f(ga,10);
	int aa[10];
	f(aa,10);
	
	return 0;
}
