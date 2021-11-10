#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("word.in");
    ofstream fout("word.out");

    int num, maxsize; fin >> num >> maxsize;

    vector<string> anime;
    string a = "";
    int size = 0; 

    for(int i = 0; i < num; i++)
    {
        string s; fin >> s;
        if(size + s.size() > maxsize)
        {
            fout << a << endl;
            /* cout << '"' << a <<  '"' <<  endl; */
            a = s;
            size = s.size();
        }
        else
        {
            if(a.size() > 0)
                a.push_back(' ');
            a += s;
            size += s.size();
        }
    }
    if(a.size() > 0)
    {
        fout << a << endl;
        /* cout << '"' << a << '"' <<  endl; */
    }
    return 0;
}
