#include "../header.h"

class BadArea {};

int area(int length,int width)
{
	if(length<=0 || width<=0) throw BadArea{};		

	return length*width;
}

int main()
{
	int x=7;
	int y=2;

try
{
	int area1=area(x,y);

	if(area1<=0) error("Bad area\n");
	cout<<"Area1= "<<area1<<"\n";
}
catch (BadArea)
{
	cerr<<"Bad area caught!\n";
}
	return 0;
}