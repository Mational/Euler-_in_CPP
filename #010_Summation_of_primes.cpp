#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool czy_pierwsza(int dane)
{
    int tmp = sqrt(dane);
    for(int j=2;j<=tmp;j++)
        if(dane%j==0)
            return false;
    return true;
}

long long sum(vector<int>&v, int l)
{
    long long s=0;
    int i=0;
    while(v[i]<=l && i<v.size())
    {
        s+=v[i];
        i++;
    }
    return s;
}

int main()
{
    vector<int> vec;
    vec.push_back(2);

    int t;
    cin >> t;
    for(int a0=0;a0<t;a0++)
    {
        int limit;
        cin >> limit;

        long long suma = sum(vec,limit);
        for(int i=vec[vec.size()-1]+1; i<=limit; i++)
            if(czy_pierwsza(i))
            {
                vec.push_back(i);
                suma+=i;
            }

        cout << suma << endl;
    }
    return 0;
}
