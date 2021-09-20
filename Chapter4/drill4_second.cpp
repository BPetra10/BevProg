#include "../header.h" 

int main()
{
	double a = 0;
	double max = 0;
	double min = 0;
	
	//1.
		cout << "Give one number:\n";	
		
	while(cin>>a)
	{
		if(a<min)
		{
			cout<<"smallest \n";
		}
		if(a>max)
		{
			cout<<"largest \n";
		}
	}
}
