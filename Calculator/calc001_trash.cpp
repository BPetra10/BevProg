#include "../header.h"

int main()
{
	cout<< "Please enter an expression:\n";

	int rightval = 0, leftval = 0;

	cin>>leftval;

	for (char op; cin>>op;)
	{
		if (op !='x') cin>>rightval;
	
	switch(op){
		case '+':
		leftval+=rightval;
		break;

		case '-':
		leftval-=rightval;
		break;

		case '*':
		leftval*=rightval;
		break;

		case '/':
		leftval/=rightval;
		break;
		
		default:
		cout<<"Result: "<<leftval<<"\n";
		return 0;
	}
	}
}