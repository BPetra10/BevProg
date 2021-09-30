#include "../header.h"

int error_code_ID=0;
int area(int length,int width)
{
	if(length<=0)
		error_code_ID=8;

	if (width<=8)
		error_code_ID=9;

	return length*width;
}
int main()
{
	int x=7;
	int y=2;

	int area1=area(x,y);

	if(error_code_ID=8) error("Bad length\n");
	if(error_code_ID=9) error("Bad width\n");

	cout<<"Area1= "<<area1<<"\n";

	return 0;
}