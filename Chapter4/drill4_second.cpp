#include "../header.h" 

int main()
{
	double a=0, min=0, max=0, sum=0, converted=0, quantity=0;
	string unit = "";
	vector<double> valuesEntered;
	bool first_enter = true;
	bool is_valid = true; 
	constexpr int m_to_cm = 100;
	constexpr double in_to_cm = 2.54;
	constexpr int ft_to_in = 12;
	//6.
	cout << "Give one number and a unit(cm,m,in,ft): \n";	
	while(cin>>a>>unit)
	{
		if (unit=="cm")
		{
			converted = a/m_to_cm;
			valuesEntered.push_back(converted);
		}
		else if(unit=="in")
		{
			converted = a*in_to_cm/m_to_cm;
			valuesEntered.push_back(converted);
		}
		else if(unit=="ft")
		{
			converted = a*ft_to_in*in_to_cm/m_to_cm;
			valuesEntered.push_back(converted);
		}
		else if(unit=="m")
		{
			converted = a;
			valuesEntered.push_back(converted);
		}
		else
		{
			is_valid = false;
		}

		if(is_valid)
		{
			sum+=converted;
			++quantity;
			if(converted<min || first_enter)
			{
				min=converted;
				cout<< min <<" m is the smallest so far"<<"\n";
			}
			
			if(converted>max || first_enter)
			{
				max=converted;
				cout<< max <<" m is the largest so far"<<"\n";
			}
			first_enter = false;
		}
		else
		{
			cout<<"Unsupported unit.\n";
		}
		is_valid=true;
	}

	sort(valuesEntered);
	for (double value: valuesEntered)
	{
		cout<<value<<"\n";
	}
	cout<<"Smallest number: "<< min <<" m\n";
	cout<<"Largest number: "<< max <<" m\n";
	cout<<"Number of values: "<< quantity <<"\n";
	cout<<"Sum of values: "<< sum <<" m\n";
	return 0;
}
