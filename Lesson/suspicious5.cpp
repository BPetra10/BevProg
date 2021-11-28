#include <vector>
#include <iostream>
#include <memory>

//alapvetően már egy unique_ptr-t várunk a függvényünknek, és adunk vissza
std::unique_ptr<std::vector<int>> suspicious()
{
	auto p= std::make_unique<std::vector<int>>();
	for (int i; std::cin>>i;)
	{
		if(i) p->push_back(i);
		else throw std::exception();
		//hiba esetén implicit módú felszabadítás lesz, hívjuk a destruktort
		//Így a p-nek is hívódik a destruktora, így felszabadul a terület
	}
	return p;
}

int main()
try
{
	auto p = suspicious();
	for (int i = 0; i < p->size(); ++i)
		std::cout<<p->at(i)<<" ";//-> mert p pointer
	std::cout<<"\n";

	return 0;
}
catch(std::exception& e){
	std::cerr<<"Error!\n";
	return 1;
}