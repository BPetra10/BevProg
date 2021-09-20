#include "../header.h" 

int main()
{
	double a;
	double max;
	double min;
	
	//6.
		cout << "Give one number: \n";	
		cin >> a;
		max = a;
		min = a;
	while(cin>>a)
	{
		if(a<min)
		{
			min=a;
			cout<< min <<" the smallest so far"<<"\n";
		}
		if(a>max)
		{
			max=a;
			cout<< max <<" the largest so far"<<"\n";
		}
	}
}
