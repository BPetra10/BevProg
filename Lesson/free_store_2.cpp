#include "../header.h"

double* calc(int res_size, int max)
{
	double* p = new double[max];
	double* res=new double[res_size];
	delete[] p; //memóriaterület felszabadítás
	return res;
}

int main()
{
	//memory leak, szivárgás
	double* r = calc(100,200);
	//memóriahasználat ellenőrzés:valgrind valgrind ./fájlnév
	delete[] r;
	return 0;
}