#include "../header.h"

int main()
{
	int a=0, b=0;
	cout<<"Please enter two value:\n";
	cin>>a>>b;
	if(a<b)
		cout<<"a<b "<<"a="<<a<<" b="<<b<<"\n";
	else if(a==b)
		cout<<"a=b "<<"a="<<a<<" b="<<b<<"\n";
	else
		cout<<"a>b "<<"a="<<a<<" b="<<b<<"\n";
	
	return 0;
}