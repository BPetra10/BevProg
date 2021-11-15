#include "../header.h"

//Which functions and calls compiled, and why?
// Az érték és referencia szerinti átadás sikeres ilyen módon megírva
void swap_v(int a,int b)
{ 
	int temp; 
	temp = a, a=b; 
	b=temp;
}

void swap_r(int& a,int& b)
{ 
	int temp; 
	temp = a, a=b; 
	b=temp; 
}

/*
Viszont konstans referencia miatt az a és a b értéke is csak 1x adható meg
azaz nem lehet őket felülírni, tehát az a=b és a b=temp itt nem valósulhat meg.
Alapvetően mivel swap-ot írunk, ahol az értékek felcserélése a feladatunk,
konstans referenciával nem valósítható meg.
*/

/*void swap_cr(const int& a, const int& b)
{ 
	int temp; 
	temp = a, a=b; 
	b=temp; 
}*/

int main()
{
	int x = 7;
	int y = 9;

	/*Azért referencia szerinti átadás, mert változókat cserélünk fel,
	és azok értékét módosítani is szeretnénk. Kiíratáskor x=9, y=7 lesz*/
	swap_r(x,y);

	/*
	swap_v(x,y);
	Ebben az esetben az értékek nem fognak felcserélődni az eredeti x és y-nál,
	hiszen az x és y másolatával dolgozunk, és nem magával x és y-nal. Itt az x éy y
	változatlan maradna.
	*/
	 
	swap_v(7,9);//Felcserélődnek

	//swap_r(7,9); 
	//cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’ 

	const int cx = 7;
	const int cy = 9;

	swap_v(cx,cy);
	/*Az érték szerinti átadás kezeli a konstansokat, viszont az eredeti cx cy
	 nem fog módusolni. Konstansokat nem lehet felüldefiniálni.*/

	//swap_r(cx,cy); 
	//error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers

	swap_v(7.7,9.9); //Felcseréli őket, de intként lesznek kezelve, azaz 9,7 lesz 

	//swap_r(7.7,9.9);
	//cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’ 

	double dx = 7.7;
	double dy = 9.9;

	swap_v(dx,dy);
	/*Nem fognak majd felcserélődni az értékek az eredeti dx és dy-nál, mivel az
	eredeti változót nem módosítjuk érték szerinti átadáskor, hanem másolattal dolgozunk.
	*/
	
	//swap_r(dx,dy);
	//Nem fog működni, mivel int referenciát várunk, de double-t akarunk átadni.
	//cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’ 

	cout<<"x: "<<x<<"\n";
	cout<<"y: "<<y<<"\n";
	cout<<"cx: "<<cx<<"\n";
	cout<<"cy: "<<cy<<"\n";
	cout<<"dx: "<<dx<<"\n";
	cout<<"dy: "<<dy<<"\n";

	return 0;
}
