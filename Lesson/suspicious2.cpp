#include "../header.h"

vector<int>* suspicious()
{
	vector<int>* p = new vector<int>;
	for (int i; cin>>i;)
	{
		//A probléma: Ha hibát dobunk a vektor feltöltése
		//közben, akkor a vektort szivárogtatjuk (memory leak)
		if(i) p->push_back(i);
		else throw std::exception();
	}
	return p;
}

int main()
try
{
	vector<int>* p = suspicious();
	for (int i = 0; i < p->size(); ++i)
		cout<<p->at(i)<<" ";//-> mert p pointer
	cout<<"\n";

	//A másik probléma még az, hogy ha le is fut a feltöltés
	//akkkor mindig valakinek meg kell hívni a delete-t is:
	delete p;

	return 0;
}
catch(std::exception& e){
	std::cerr<<"Error!\n";
	return 1;
}