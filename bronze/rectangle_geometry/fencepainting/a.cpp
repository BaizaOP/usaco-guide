#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("paint.in");
    ofstream fout("paint.out");

    int a, b, c, d; fin >> a >> b >> c >> d;
   
    //get min
    int min = 0;
    bool amin = false;
    if(a < c)
    {
        min = a;
        amin = true;
    }
    else 
        min = c;
   
    //get max
    int max = 0;
    bool bmax = false;
    if(b >= d)
    {
        max = b;
        bmax = true;
    }
    else 
        max = d;
    
    int dist = max - min;
    if(amin && !bmax) 
    {
        if(b < c)
        {
            dist = dist + b - c;
        }
    }
    else if(bmax && !amin)
    {
        if(d < a)
        {
            dist = dist + d - a;
        }
    }
    cout << dist << endl;
    fout << dist << endl;
    return 0;
}
