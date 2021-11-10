#include <bits/stdc++.h>
using namespace std;

int overlap (int a, int b, int x, int y);

int main()
{
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int ax, ay, bx, by; fin >> ax >> ay >> bx >> by;
    int cx, cy, dx, dy; fin >> cx >> cy >> dx >> dy;
    int tx, ty, ux, uy; fin >> tx >> ty >> ux >> uy;

    int alength = max(ax - bx, bx - ax);
    int aheight = max(ay - by, by - ay);
    int aarea = alength * aheight;
    int clength = max(cx - dx, dx - cx);
    int cheight = max(cy - dy, dy - cy);
    int carea = clength * cheight;

    int area = aarea + carea;

    int ax_overlap = overlap(ax, bx, tx, ux); 
    int ay_overlap = overlap(ay, by, ty, uy);
    int a_overlapped_area = ax_overlap*ay_overlap;
    
    area -= a_overlapped_area;

    int cx_overlap = overlap(cx, dx, tx, ux);
    int cy_overlap = overlap(cy, dy, ty, uy);
    int c_overlapped_area = cx_overlap * cy_overlap;

    area -= c_overlapped_area;

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
