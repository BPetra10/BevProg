#include "../header.h"
int main()
try {
//1. Cout << "Success!\n";
cout<< "1. Success!\n";

//2. cout << "Success!\n;
cout << "2. Success!\n";

//3. cout << "Success" << !\n"
cout << "3. Success" << "!\n";

//4. cout << success << '\n';
cout << "4. success" << '\n';

//5. string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
int res = 7; 
vector<int> v(10); 
v[5] = res; 
cout << "5. Success!\n";

//6. vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";
vector<int> ve(10);  
ve[5] = 7; 
if (ve[5]==7)  cout << "6. Success!\n";

//7. if (cond) cout << "Success!\n"; else cout << "Fail!\n";
if (1>0)  
cout << "7. Success!\n"; 
else 
cout << "Fail!\n";

//8. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
bool c = true; 
if (c) 
cout << "8. Success!\n"; 
else 
cout << "Fail!\n";

//9. string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n"; ??????
string s = "ape"; 
string d ="fool";
bool is_true;
if(s<d)
is_true = true; 
if (is_true) cout << "9. Success!\n";

//10. string s = "ape"; if (s=="fool") cout << "Success!\n";
string e = "ape"; if (e!="fool") cout << "10. Success!\n";

//11. string s = "ape"; if (s=="fool") cout < "Success!\n";
string f = "ape"; if (f!="fool") cout <<"11. Success!\n";

//12. string s = "ape"; if (s+"fool") cout < "Success!\n";
string g = "ape"; if (g!="fool") cout << "12. Success!\n";

//13. vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n";
vector<char> vec(5);
for (int i=0; i<vec.size(); ++i) 
cout << "13. Success!\n";

//14. vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
vector<char> vect(5); 
for (int i=0; i<vect.size(); ++i) 
cout << "14. Success!\n";

//15. string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
string st = "Success!\n"; 
for (int i=0; i<6; ++i) 
cout << "15. "<<st;
//16. if (true) then cout << "Success!\n"; else cout << "Fail!\n";
if (true) cout << "16. Success!\n"; else cout << "Fail!\n";
//17. int x = 2000; char c = x; if (c==2000) cout << "Success!\n";

//18. string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];

//19. vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";

//20. int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";

//21. int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n";
int y = 2; 
double z = 4.5/(y-1); 
if (z==2*y+0.5) 
cout << "21. Success!\n";

//22. string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];

//23. int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n";

//24. int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n";

//25. cin << "Success!\n";
return 0;
}
catch (exception& e) {
cerr << "error: " << e.what() << '\n';
return 1;
}
catch (...) {
cerr << "Oops: unknown exception!\n";
return 2;
}
