#include "../header.h"

int area(int length,int width)
{
	if(length<=0 || width<=0)
		return -1;

	return length*width;
}
int main()
{
	int x=7;
	int y=2;

	int area1=area(x,y);

	if(area1<=0) error("Bad area\n");
	cout<<"Area1= "<<area1<<"\n";

	return 0;
}