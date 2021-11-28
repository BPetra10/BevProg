#include <vector>
#include <iostream>
#include <memory>

std::vector<int> suspicious()
{
	std::vector<int> p;
	for (int i; std::cin>>i;)
	{
		if(i) p.push_back(i);
		else throw std::exception();
		//hiba esetén implicit módú felszabadítás lesz, hívjuk a destruktort
		//Így a p-nek is hívódik a destruktora, így felszabadul a terület
	}
	return p; //Move:
	//Egy vektort szeretnénk, hogy egy másikra hivatkozzon, 
	//anélkül, hogy másolnánk egyik vektorból, a másikba
	//Az első vektor elemeinek a pointerét és elemszámát
	//átadjuk a másiknak, így sikeresen átkerültek az elemek.
	//Az első vektor így törölhetővé válik.
}

int main()
try
{
	auto p = suspicious();
	for (int i = 0; i < p.size(); ++i)
		std::cout<<p.at(i)<<" ";
	std::cout<<"\n";

	return 0;
}
catch(std::exception& e){
	std::cerr<<"Error!\n";
	return 1;
}