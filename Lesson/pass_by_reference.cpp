#include "../header.h"
//referencia szerinti paraméterátadás
int f(int& x)
{
	x= x+1;
	return x;
}

int main()
{
	int xx=42; //Az xx értéke módosulni fog a függvénymeghívás után
	cout<<f(xx)<<"\n";
	cout<<xx<<"\n";

	int yy<<f(yy)<<"\n";
	cout<<yy<<"\n";

	return 0;
}