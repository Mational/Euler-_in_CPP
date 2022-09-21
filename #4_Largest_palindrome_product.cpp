#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void program(int l)
{
    int h = l/1000, n;
    string ls;
    for(h;h>=101;h--)
    {
        ls = to_string(h);
        reverse(ls.begin(),ls.end());
        ls = to_string(h)+ls;
        n=stoi(ls);
        if(n>=l) continue;
        for(int i=100;i<1000;i++)
            if(n%i==0 && (int)log10(n/i)+1==3)
            {
                cout << n << endl;
                return;
            }
    }
}

int main()
{
    int t;
    cin >> t;
    for(int a0=0;a0<t;a0++)
    {
        int limit;
        cin >> limit;
        program(limit);
    }
    return 0;
}

