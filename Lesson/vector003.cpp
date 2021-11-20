#include "../header.h"

class My_vector
{
	int sz; //size
	double* elem;//a tömbre mutat, amiben tárolódnak az elemek
	void debug(const string& s)//objektum cím, üzenet, és elem pointer cím kiírás
	{
		cerr<<this<<"->"<<s<<"; elem ptr: "<<elem<<"\n";
	}

public:
	My_vector():sz{0},elem{nullptr}{}//alapértelmezett konstruktor
	My_vector(int s):sz{s},elem{new double[s]}//konstruktor elemszáma
	{
		for (int i = 0; i < sz; ++i) elem[i]=0; //minden elem 0 kezdőérték
		//debug("(int s) constructor");
	}
	My_vector(initializer_list<double> lst):sz{lst.size()},elem{new double[sz]}
	{
		copy(lst.begin(),lst.end(),elem);
		//debug("(initializer_list<double> lst) constructor");
	}
	My_vector(const My_vector& arg):
	sz{arg.sz},elem{new double[arg.sz]}
	{
		copy(arg.elem,arg.elem+arg.sz,elem);
		//debug("copy constructor");
	}
	My_vector& operator=(const My_vector& arg)
	{
		double* p=new double[arg.sz];
		copy(arg.elem,arg.elem+arg.sz,p);
		delete[] elem;
		sz=arg.sz;
		elem = p;
		//debug("copy assignment");
		return *this;
	}
	My_vector(My_vector&& arg):sz{arg.sz},elem{arg.elem}//&& mozgatás
	{
		arg.sz=0;
		arg.elem=nullptr;
		//debug("move constructor");
	}
	My_vector& operator=(My_vector&& arg)
	{
		delete[] elem;
		elem = arg.elem;
		sz=arg.sz;
		arg.elem=nullptr;
		arg.sz=0;
		//debug("move assignment");
		return *this;
	}
	~My_vector()//destruktor ~des{felszabadítás}
	{ 
		//debug("destructor"); 
		delete[] elem;
	} 
	//blokk végén fut le a destruktor
	double& operator[](int n){return elem[n];}//n-edik elem elérése
	double operator[](int n) const{return elem[n];}
	//double get(int n) const{return elem[n];}//n-edik elem visszaadás
	//void set(int n,double d) {elem[n]=d;}//n-edik elem értéke
	int size() const{return sz;}//elemszám
};

My_vector* some_fct()
{
	My_vector* myvec = new My_vector(10);//10 elemű myvector free-storeban
	return myvec;
}
My_vector fill()
{
	My_vector res={12.2,13.3,14.4};
	return res;
}

int main()
{
	My_vector v1{12.2,13.3,14.4,15.5};

	for(int i = 0; i < v1.size(); ++i)
		cout<<v1[i]<<" ";
	cout<<"\n";

	My_vector v2(10);
	for(int i = 0; i < v2.size(); ++i)
		v2[i]=i;
	for(int i = 0; i < v2.size(); ++i)
		cout<<v2[i]<<" ";
	cout<<"\n";
	return 0;
}