#include "../header.h" 
//1-6ig kell megírni a drillt, majd egy másikat a 6-tól 11-ig
//7-es esetleg switch case
int main()
{
	double a = 0;
	double b = 0;
	//1.
		cout << "Give two number:\n";	
		
	while(cin>>a>>b)
	{
		//1.
		cout<<"a number: " << a << " b number: "<< b << "\n";
		
		//2.
		if(a>b)
		{
			cout<<" the smaller value is: "<< b << "\n";
			cout<<" the larger value is: "<< a << "\n";
			if(a-b<0.1)
			{
				cout<<" the two number are almost equal. \n";
			}
		}
		else if(b>a)
		{
			cout<<" the smaller value is: "<< a << "\n";
			cout<<" the larger value is: "<< b << "\n";
			if(b-a<0.1)
			{
				cout<<" the two number are almost equal. \n";
			}
		}
		else
		{
			//3.
			cout<<" the two number are equal. \n";
		}
	}
	return 0;
}

