#include "../header.h"
int main()
{
    int x = 120, y = 52;
    x = x + y; 
    y = x - y;
    x = x - y; 
    cout << "x=" << x << " y=" << y<<"\n";
}
