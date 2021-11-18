#include "../header.h"

class My_vector
{
	int sz; //size
	double* elem;//a tömbre mutat, amiben tárolódnak az elemek
public:
	My_vector(int s):sz{s},elem{new double[s]}//konstruktor elemszáma
	{
		for (int i = 0; i < sz; ++i) elem[i]=0; //minden elem 0 kezdőérték
	}
	~My_vector(){ delete[] elem;}//destruktor ~des{felszabadítás} 
	//blokk végén fut le a destruktor
	double get(int n) const{return elem[n];}//n-edik elem visszaadás
	void set(int n,double d) {elem[n]=d;}//n-edik elem értéke
	int size() const{return sz;}//elemszám
};

My_vector* some_fct()
{
	My_vector* myvec = new My_vector(10);//10 elemű myvector free-storeban
	return myvec;
}

int main()
{
	My_vector mv(10);
	cout<<mv.size()<<"\n";
	for (int i = 0; i < mv.size(); ++i)
		mv.set(i,i*0.5);
	for (int i = 0; i < mv.size(); ++i)
		cout<<mv.get(i)<<" ";
	cout<<"\n";

	My_vector* myptr = some_fct();
		cout<<myptr->size()<<"\n";//pointernél objektum tagra -> hivatkozunk

	delete myptr;
	
	return 0;
}