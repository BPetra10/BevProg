#include "../header.h" 

int main()
{
	double a;
	double max;
	double min;
	string unit;
	constexpr int m_to_cm = 100;
	constexpr double in_to_cm = 2.54;
	constexpr int ft_to_in = 12;
	
	//6.
		cout << "Give one number and a unit(cm,m,in,ft): \n";	
		cin >> a >> unit;
		max = a;
		min = a;
		
	while(cin>>a>>unit)
	{
		if(a<min)
		{
			if(unit=="cm" || unit=="m" || unit=="in" || unit=="ft")
			{
				min=a;
				cout<< min <<" the smallest so far"<<"\n";
			}
			else
			{
				cout << "Unsopported unit.\n";
			}
		}
		else if(a>max)
		{
			if(unit=="cm" || unit=="m" || unit=="in" || unit=="ft")
			{
				max=a;
				cout<< max <<" the largest so far"<<"\n";
			}
			else
			{
				cout << "Unsopported unit.\n";
			}
		}
		else
		{
			cout << "Unsopported unit.\n";
		}
	}

	return 0;
}
