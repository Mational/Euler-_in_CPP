#include <iostream>
#include <map>
#include <vector>

using namespace std;

int collatz(long long liczba, map<int, unsigned short>&m)
{
    if(liczba == 1) return 0;

    if(m[liczba] == 0)
        if(liczba%2 == 0)   m[liczba] = collatz(liczba/2, m) + 1;
        else                m[liczba] = collatz((liczba*3+1)/2, m) + 2;

    return m[liczba];
}

int program(int n, vector<int>&v, map<int, unsigned short>&m)
{
    if(v.size() > n)   return v[n];
    int max_liczba = v[v.size()-1];
    int maks_lancuch = m[max_liczba];

    int dl;
    for(int i=v.size();i<=n;i++)
    {
        dl=collatz(i, m);
        m[i] = dl;
        if(dl>=maks_lancuch)
        {
            maks_lancuch=dl;
            max_liczba=i;
        }
        v.push_back(max_liczba);
    }
    return max_liczba;
}

int main()
{
    int t;
    cin >> t;
    vector<int> v {0, 1, 2};
    map<int, unsigned short> collatz_len;
    collatz_len[1] = 0;
    collatz_len[2] = 1;
    for(int a0=0;a0<t;a0++)
    {
        int n;
        cin >> n;
        cout << program(n, v, collatz_len) << endl;
    }
    return 0;
}
