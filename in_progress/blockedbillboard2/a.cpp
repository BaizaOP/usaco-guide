#include <bits/stdc++.h>
using namespace std;

int overlap (int a, int b, int x, int y);

int main()
{
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int ax, ay, bx, by; fin >> ax >> ay >> bx >> by;
    int tx, ty, ux, uy; fin >> tx >> ty >> ux >> uy;

    ax += 3000;
    ay += 3000;
    bx += 3000;
    by += 3000;
    tx += 3000;
    ty += 3000;
    ux += 3000;
    uy += 3000;

    int dx = bx - ax;
    int dy = by - ay;
    int area = dx * dy;
    
    int xoverlap = overlap(ax, bx, tx, ux);
    int yoverlap = overlap(ay, by, ty, uy);
    if(xoverlap == dx || yoverlap == dy) 
        area -= (xoverlap * yoverlap);

    cout << area << endl;
    fout << area << endl;

    return 0;
}

int overlap (int a, int b, int x, int y)
{
    if((a > y) || (b < x)) 
        return 0;     //X---Y---A---B or A---B---X---Y
    if((a <= x) && (b >= y)) 
        return y-x; //A---X---Y---B
    if((a >= x) && (b <= y)) 
        return b-a; //X---A---B---y
    else if(a > x) 
        return y-a;
    else if(b < y) 
        return b-x;
    else 
        return -1;
}
