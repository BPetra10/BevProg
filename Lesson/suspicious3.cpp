#include <vector>
#include <iostream>
#include <memory>

std::vector<int>* suspicious()
{
	std::unique_ptr<std::vector<int>> p {new std::vector<int>};
	//a new-nál még keletkezhetnek hibák, ezért használjuk majd a make_unique-ot
	/*
	  unique pointer az egy RAII (Resource Acquisition Is Initialization)
	  "erőforrás megszerzés és inicializálás" módszer, melynek segítségével a
	  vektort tudjuk törölni, ha hibát kapnánk még felszabadítás előtt.
	  Ez a unique ptr a <memory> standard library-ben van, és biztosítja, hogy
	  hiba esetén ne legyen memóriaszivárgás.
	*/
	/*
	A unique_ptr-re tekinthetünk úgy, mint egy sima pointerre, viszont, ha egy
	unique_ptr törölve/megsemmisítve lesz, akkor ez a ptr törli azt is, amilyen 
	objektumra mutat. 
	Emellett nevéből is adódóan, egy objektumra egy unique-ptr állítható, mert
	a törlés miatt problémák adódhatnának.
	*/
	for (int i; std::cin>>i;)
	{
		if(i) p->push_back(i);
		else throw std::exception();
		//hiba esetén implicit módú felszabadítás lesz, hívjuk a destruktort
		//Így a p-nek is hívódik a destruktora, így felszabadul a terület
	}
	return p.release();//Felszabadítja a pointert
	//visszaadja az értékét, és lecseréli nullptr-re
	//nem semmisíti meg az objektumot, de a unique_ptr mentesül a törlés alól
}

int main()
try
{
	std::vector<int>* p = suspicious();
	for (int i = 0; i < p->size(); ++i)
		std::cout<<p->at(i)<<" ";//-> mert p pointer
	std::cout<<"\n";

	delete p;

	return 0;
}
catch(std::exception& e){
	std::cerr<<"Error!\n";
	return 1;
}