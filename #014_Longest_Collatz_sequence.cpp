#include <iostream>
#include <vector>

using namespace std;

void collatz(long long liczba, vector<int>&cl)
{
    long long current = liczba;
    int chain = 0;
    while(true)
    {
        if(current<liczba)
        {
            cl[liczba] = chain + cl[current];
            return;
        }
        if(current%2==0)
        {
            current/=2;
            chain++;
        }
        else
        {
            current = (current*3+1)/2;
            chain+=2;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int tab[t];
    int m = 0;
    for(int a0=0;a0<t;a0++)
    {
        cin >> tab[a0];
        if(tab[a0]>m) m=tab[a0];
    }

    vector<int> chain_len(m+1);
    vector<int> answer(m+1);

    for(int i=2;i<=m;i++)
        collatz(i, chain_len);

    int curmax = 1;
    int curindex = 1;
    for(int i=2;i<=m;i++)
    {
        if(chain_len[i] >=curmax)
        {
            curmax = chain_len[i];
            curindex = i;
        }
        answer[i] = curindex;
    }

    for(auto i:tab)
        cout << answer[i] << endl;
    return 0;
}
