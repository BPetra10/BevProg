#include "../header.h"

int square(int y) //Függvény bevezetése
{
	return y*y;
}

void print_square(int z)
{
	cout << z << '\t' << square(z) << '\n';
}

int main()
{
	for (int i = 0; i < 100; ++i)
		print_square(i);
		//cout << i << '\t' << square(i) << '\n';
		
	int x = 0;
	while(x<100)
	{
		cout << x << '\t' << x*x << '\n';
		++x;
	}

	return 0;
}