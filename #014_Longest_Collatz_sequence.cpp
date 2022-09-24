#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<long long, int> collatz_len;

int collatz(long long liczba)
{
    if(liczba == 1) return 0;

    if(collatz_len[liczba] == 0)
        if(liczba%2 == 0)   collatz_len[liczba] = collatz(liczba/2) + 1;
        else                collatz_len[liczba] = collatz(liczba*3+1) + 1;

    return collatz_len[liczba];
}

int program(int length, vector<long long>&v)
{
    if(v.size() > length)   return v[length];
    int max_liczba = v[v.size()-1];
    int maks_lancuch = collatz_len[max_liczba];

    int dl;
    for(int i = v.size();i<=length;i++)
    {
        dl=collatz(i);
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
    collatz_len[1] = 0;
    collatz_len[2] = 1;
    vector<long long> v {0, 1, 2};
    for(int a0=0;a0<t;a0++)
    {
        int length;
        cin >> length;
        cout << program(length, v) << endl;
    }
    return 0;
}
