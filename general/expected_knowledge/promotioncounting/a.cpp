#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("promote.in", "r", stdin); 
    freopen("promote.out", "w", stdout);

    int bronzeb, bronzea, silverb, silvera, goldb, golda, platb, plata;
    cin >> bronzeb >> bronzea;
    cin >> silverb >> silvera;
    cin >> goldb >> golda;
    cin >> platb >> plata;

    int sumb = bronzeb + silverb + goldb + platb;
    int suma = bronzea + silvera + golda + plata;

    int startb = suma - sumb;
    int starta = 0;
    startb -= starta;
    bronzeb += startb;
    bronzeb -= bronzea;
    cout << bronzeb << endl;
    silverb += bronzeb;
    silverb -= silvera;
    cout << silverb << endl;
    goldb += silverb;
    goldb -= golda;
    cout << goldb << endl;

    return 0;
}

