#include "../header.h"

int main()
{
	//sizeof() típusok méretének lekérdezéséhez 
	cout<<"The size of an char is: "<<sizeof(char)<<"byte. \n";
	cout<<"The size of an int is: "<<sizeof(int)<<"bytes. \n";
	cout<<"The size of an double is: "<<sizeof(double)<<"bytes. \n";

	cout<<"The size of an char* is: "<<sizeof(char*)<<"byte. \n";
	cout<<"The size of an int* is: "<<sizeof(int*)<<"bytes. \n";
	cout<<"The size of an double* is: "<<sizeof(double*)<<"bytes. \n";
	return 0;
}