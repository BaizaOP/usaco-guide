#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long> anime;
    for(int i = 0; i < 7; i++)
    {
        long long x; cin >> x;
        anime.push_back(x);
    }
    sort(anime.begin(), anime.end());
    /* for(long long i : anime) cout << i << endl; */
    long long a = anime[0];
    long long b = anime[1];
    long long c = anime[6] - a - b;
    cout << a << " " << b << " " << c << endl;
    return 0;

}
