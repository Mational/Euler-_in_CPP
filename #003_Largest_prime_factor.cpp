#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int a0=0;a0<t;a0++)
    {
        long long l;
        cin >> l;

        for(long long i=2;i*i<=l;i++)
            while(l%i==0 && l/i!=1)
                l/=i;

        cout << l << endl;
    }
    return 0;
}
