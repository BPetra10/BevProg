#include "../header.h"

double expression();

class Token //classban szoktunk saját típust írni
{
public:
	char kind; //típus/fajta
	double value; //érték
	//konstruktor:
	Token(char ch): kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
};

Token get_token(){
	char ch; //Karakterenként olvassuk a bemenetet
	cin >> ch;

	switch(ch){
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
			return Token('8',val);
		}
		default:
			simple_error("Bad token");
			return 0;
	}
}

double primary() //zárójelek és számok kezelése
{
	Token t = get_token();
	switch(t.kind){
		case '(':
		{
			double d = expression();
			t = get_token(); //bezáró zárójel
			if(t.kind !=')') error(") expected");
			return d;
		}
		case '8':
			return t.value;
		default:
			error("primary expected");
			return 0;
	}
}

double term()
{
	double left = primary();
	Token t = get_token();

	while(true)
	{
		switch(t.kind){
			case '*':
				left *= primary();
				t = get_token();
				break;
			case '/':
				left /= primary();
				t = get_token();
				break;
			/*
			case '%':
				left %= primary();
				t = get_token();
				break;
			*/
			default:
				return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = get_token();

	//TODO: Token típus megírás
	while(true)
	{
		switch(t.kind){
			case '+':
				left +=term();
				t=get_token();
				break;
			case '-':
				left -=term();
				t=get_token();
				break;
			default:
				return left;
		}
	}
}

int main()
try{

	while(cin) //Amíg tud beolvasni, addig fut
	 cout<<"Result:"<<expression()<<"\n";


	return 0;

}catch (exception& e)
{
	cerr << "Error: "<<e.what()<<"\n";
}