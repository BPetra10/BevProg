#include "../header.h"

class My_out_of_range{};

class My_vector
{
	int sz; //size
	double* elem;//a tömbre mutat, amiben tárolódnak az elemek
	void debug(const string& s)//objektum cím, üzenet, és elem pointer cím kiírás
	{
		cerr<<this<<"->"<<s<<"; elem ptr: "<<elem<<"\n";
	}
	int space;

public:
	My_vector():sz{0},elem{nullptr},space{0}{}//alapértelmezett konstruktor
	explicit My_vector(int s):sz{s},elem{new double[s]},space{s}//konstruktor elemszáma
	{
		for (int i = 0; i < sz; ++i) elem[i]=0; //minden elem 0 kezdőérték
		//debug("(int s) constructor");
	}
	My_vector(initializer_list<double> lst):sz{lst.size()},elem{new double[sz]},space{sz}
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
		if(this==&arg) return *this;
		if(arg.sz<=space)
		{
			for (int i = 0; i < arg.sz; ++i)elem[i]=arg.elem[i];
			sz=arg.sz;
			return *this;
		}
		double* p=new double[arg.sz];
		copy(arg.elem,arg.elem+arg.sz,p);
		delete[] elem;
		space=arg.sz;
		sz=arg.sz;
		elem = p;
		//debug("copy assignment");
		return *this;
	}
	My_vector(My_vector&& arg):sz{arg.sz},elem{arg.elem},space{arg.space}//&& mozgatás
	{
		arg.sz=0;
		arg.space=0;
		arg.elem=nullptr;
		//debug("move constructor");
	}
	My_vector& operator=(My_vector&& arg)
	{
		delete[] elem;
		elem = arg.elem;
		sz=arg.sz;
		space=arg.space;
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
	int capacity() const {return space;}

	void reserve(int newalloc)//memóriafoglalás
	{
		if(newalloc<=space) return;
		double* p=new double[newalloc];
		for (int i = 0; i < sz; ++i) p[i]=elem[i];
		delete[] elem;
		elem = p;
		space=newalloc;
	}

	void resize(int newsize)
	{
		reserve(newsize);//megnézi kell-e több memória
		for (int i = sz; i < newsize; ++i) elem[i]=0;
		sz=newsize;
	}

	void push_back(double d)
	{
		if(sz==0) //üres-e a vektor
			reserve(8);
		else if(sz==space)
			reserve(2*space);
		elem[sz]=d;
		++sz;
	}

	double& at(int n)
	{
		if(n<0 || sz<=n) throw My_out_of_range{};
		return elem[n];
	}

	double at(int n) const
	{
		if(n<0 || sz<=n) throw My_out_of_range{};
		return elem[n];
	}
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
try{
	My_vector v1;
	 cout<<"\t size: "<<v1.size()<<" ";
	 cout<<"\t space: "<<v1.capacity()<<"\n";

	for(int i = 0; i < 9; ++i)
	{
		v1.push_back(i);
		cout<<v1[i]<<" ";
	    cout<<"\t size: "<<v1.size()<<" ";
	    cout<<"\t space: "<<v1.capacity()<<"\n";
	}
		
	return 0;
}catch(My_out_of_range){
	cerr<<"out of range!\n";
	return 1;
}