#include "../header.h"

constexpr char number='8';
constexpr char print=';';
constexpr char quit='q';

double expression();

/*
Token lényege: a beírt értékek karakterként vannak kezelve.
A számokat is karakterek sorozataként értelmezi. 
A Token lényege, hogy összeszedi a különböző típusú dolgokat: 
pl.: a számokat, vezérlőkaraktereket, műveleti jeleket.
Ha a token szám, akkor azt a value-ba tároljuk.
*/

class Token //classban szoktunk saját típust írni
{
public:
	char kind; //típus/fajta
	double value; //érték
	//konstruktor:
	Token(char ch): kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
};

class Token_stream{
public:
	Token_stream();
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full{false};
	Token buffer;
};

Token_stream:: Token_stream():full{false}, buffer(0) {}

void Token_stream::putback(Token t){
	if (full) simple_error("Token_stream buffer is full\n");
	full=true;
	buffer=t;
}

Token Token_stream::get(){
	if(full)
	{
		full=false;
		return buffer;
	}
	char ch; //Karakterenként olvassuk a bemenetet
	cin >> ch;

	switch(ch){
		case quit:
		case print:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			return Token(ch);
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val = 0;
			cin >> val;
			return Token(number,val);
		}
		default:
			simple_error("Bad token");
			return 0;
	}
}

void Token_stream::ignore(char c){ //A helytelenül megadott műveleteket kipucoljuk
	if (full && c==buffer.kind)//;
	{
		full=false;
		return;
	}
	full=false;

	char ch = 0;
	while(cin>>ch)
		if(ch==c) return;
}

Token_stream ts; 
//A token stream lényege, hogy ha egy adott függvény olyan tokent kap, 
//amit nem kezel, akkor azt visszarakjuk a tokent, hogy más függvény értékelhesse ki

double primary() //zárójelek és számok kezelése
{
	Token t = ts.get();
	switch(t.kind){
		case '(':
		{
			double d = expression();
			t = ts.get(); //bezáró zárójel
			if(t.kind !=')') error(") expected");
			return d;
		}
		case number:
			return t.value;
		case '-':
			return - primary();
		case '+':
			return primary();
		default:
			ts.putback(t);
			error("primary expected");
			return 0;
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();

	while(true)
	{
		switch(t.kind){ //t.kind == Token típusa
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();//Ha case ágban változót deklarálunk, kell {}
				if(d==0) error("Zero value in %\n");
				left /= d;
				t = ts.get();
				break;
			}
			case '%':
			{
				/*double d = primary(); 
				if(d==0) error("Zero value in %\n");
				//left %= primary();
				left = fmod(left,d);
				t = ts.get();
				break;*/

				//Csak egészeket engedünk: 
				int i1= narrow_cast<int>(left);
				// narrow_cast(): értékvesztés nélkül sikerül e intté alakítani
				int i2= narrow_cast<int>(primary());
				if(i2==0) error("Zero value in %\n");
				left = i1%i2;
				t = ts.get();
				break;
			}
			default:
			ts.putback(t);
				return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();

	while(true)
	{
		switch(t.kind){
			case '+':
				left +=term();
				t=ts.get();
				break;
			case '-':
				left -=term();
				t=ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

void calculate(){

	while(cin)
	try{//Amíg tud beolvasni, addig fut
		Token t = ts.get();
		while(t.kind==print) t = ts.get();
		if (t.kind==quit) return; // kiléptet
		ts.putback(t);
		cout <<"="<<expression()<<'\n';
	}catch(exception& e){
		cerr<<e.what()<<"\n";
		clean_up_mess();
	}
}

int main()
try{
	calculate();
	return 0; 	 
}catch (exception& e){
	cerr << "Error: "<<e.what()<<"\n";
	return 1;
}