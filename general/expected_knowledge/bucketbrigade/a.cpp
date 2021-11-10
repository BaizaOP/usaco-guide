#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");
    /* vector<vector<char>> anime; */
    int lx, ly, bx, by, rx, ry;
    for(int j = 0; j < 10; j++)
    {
        /* anime.push_back({}); */
        for(int i = 0; i < 10; i++)
        {
            char c;
            fin >> c;
            switch(c)
            {
                case 'L':
                    lx = i;
                    ly = j;
                    break;
                case 'B':
                    bx = i;
                    by = j;
                    break;
                case 'R':
                    rx = i;
                    ry = j;
                    break;
                default:
                    break;
            }
            /* anime[j].push_back(c); */
        }
    }
    /* for(vector<char> i : anime) */
    /* { */
    /*     for(char c : i) */
    /*         cout << c; */
    /*     cout << endl; */
    /* } */
    int ans = 300;
    //case 1 + 2
    if(lx == bx)
    {
        if(lx == rx) 
        {
            if((ry > by) && (ry < ly))
                ans = ly - by + 1; 
            else if((ry < by) && (ry > ly))
                ans = by - ly + 1;
            else
                ans = ((by > ly) ? by - ly - 1 : ly - by - 1);
        } 
        else
            ans = ((by > ly) ? by - ly - 1 : ly - by - 1);
    }
    //case 3 + 4
    else if(ly == by)
    {
        if(ly == ry)
        {
            if((rx > bx) && (rx < lx))
                ans = lx - bx + 1; 
            else if((rx < bx) && (rx > lx))
                ans = bx - lx + 1;
            else
                ans = ((bx > lx) ? bx - lx - 1 : lx - bx - 1);
        } 
        else
            ans = ((bx > lx) ? bx - lx - 1 : lx - bx - 1);
    }
    else //case 5 ez
    {
        int dx = ((bx > lx) ? bx - lx : lx - bx);
        int dy = ((by > ly) ? by - ly : ly - by);
        ans = dx + dy - 1;
    }
    /* printf("l(%d, %d), b(%d, %d), r(%d, %d)\n", lx, ly, bx, by, rx, ry); */
    /* cout << ans << endl; */
    fout << ans << endl;
    return 0;
}
