#include "header.h"

//2.
struct Point 
{
    int x;
    int y;
};

istream& operator>>(istream& is, Point& p)
{
    char first;
    if (is >> first && first != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    char last;
    int xx;
    int yy;
    is >> xx >> ch2 >> yy >> last;
    if (!is || last != ')') {
        if (is.eof()) return is;
        error("bad point");
    }
    p.x = xx;
    p.y = yy;
    return is;
}

//3.
ostream& operator<<(ostream& os, Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')'<<'\n';
}

//5.
void fill_from_file(vector<Point>& points, string& name)
{
    ifstream ist {name};

    if (!ist) error("can't open input file ", name);
    for (Point p; ist >> p; )
        points.push_back(p);
}

int main()
try {
    //2.
    cout<<"Please give 7 (x,y) pair: \n";
    vector<Point> original_points;

    while (original_points.size() < 7) {
        Point p;
        cin >> p;
        original_points.push_back(p);
    } 

    //3.
    cout<<"original_points's datas:\n";
    for (Point p : original_points)
        cout << p;

    //4.
    string fname = "mydata.txt";
    ofstream ost { fname };
    if (!ost) error("could not open file ", fname);

    for (Point p : original_points)
        ost << p;
    ost.close();

    //5.
    vector<Point> processed_points;
    fill_from_file(processed_points, fname);

    cout<<"processed_points's datas:\n";
    for (Point p : processed_points)
        cout << p;

    if (original_points.size() != processed_points.size())
        cout << "Something's wrong!\n";
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Something terrible has happened!\n";
    return 2;
}