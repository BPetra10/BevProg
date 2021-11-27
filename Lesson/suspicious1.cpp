#include "../header.h"

void suspicious(int size, int x)
{
	int* p = new int[size];
	if(x == 0) throw std::exception();
	//A probléma: memória szivárgás
	//Mivel ha exception-t dobunk, a delete[] nem fog meghívódni
	delete[] p;
}

int main()
try
{
	suspicious(5,0);
	return 0;
}
catch(std::exception& e){
	std::cerr<<"Error!\n";
	return 1;
}