#include <bits/stdc++.h>

using namespace std;

void print(int n, ofstream &fout)
{
    cout << n << endl;
    fout << n << endl;
}

bool matching(int a, int b, int x, int y, ofstream &fout);
bool doubles(int a, int b, int x, int y, ofstream &fout);
bool between(int a, int b, int x, int y, ofstream &fout);
bool alternating(int a, int b, int x, int y, ofstream &fout);

int main()
{
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");

    int a, b, x, y, temp; fin >> a >> b >> x >> y;

    if(a > b) //trichotomy property, if they are not equal, one has to be greater than another
    {
        temp = a;
        a = b;
        b = temp;
    }
    if(x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(matching(a,b,x,y,fout)) return 0; 
    if(doubles(a,b,x,y,fout)) return 0; 
    if(between(a,b,x,y,fout)) return 0;
    if(alternating(a,b,x,y,fout)) return 0;
    
    fout.close();
    fin.close();
    return 0;
}

bool matching(int a, int b, int x, int y, ofstream &fout)
{
    int dist = b - a; 
    //the zero cases
    if(a == b) //identical
    {
        print(0, fout); 
        return true;
    }
    if((x == y) || (a == y) || (b == x)) //identical
    {
        print(dist, fout); 
        return true;
    }
    if(a == x)
    {
        int n = abs(b - y);
        print(((n < dist) ? n : dist), fout);
        return true;
    }
    if(b == y)
    {
        int n = abs(a - x);
        print(((n < dist) ? n : dist), fout);
        return true;
    }
    return false;
}

bool doubles(int a, int b, int x, int y, ofstream &fout)
{
    int dist = b - a;
    if((y < a) || (x > b))
    {
        print(dist, fout); 
        return true;
    }
    return false;
}

bool between(int a, int b, int x, int y, ofstream &fout)
{
    int dist = b-a;
    if((a > x) && (b < y))
    {
        int otherdist = (a - x) + (y - b); 
        print(((dist < otherdist) ? dist : otherdist), fout); //xaby
        return true;
    }
    if((x > a) && (y < b))
    {
        int sum = (x - a) + (b - y); // axyb
        print(sum, fout);
        return true;
    }
    return false;
}
bool alternating(int a, int b, int x, int y, ofstream &fout)
{
    int dist = b - a;
    if(y > b)
    {
        int ax = x - a;
        int by = y - b;
        int sum = ax + by;
        print(((dist < sum) ? dist : sum), fout);
        return true;
    }
    else
    {
        int xa = a - x;
        int yb = b - y;
        int sum = xa + yb;
        print(((dist < sum) ? dist : sum), fout);
        return true;
    }
    return false;
}

