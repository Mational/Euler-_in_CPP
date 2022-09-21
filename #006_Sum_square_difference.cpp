#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int a0=0;a0<t;a0++)
    {
        int limit;
        cin >> limit;
        long long s=0, sq_sum=0;
        for(int i=1; i<=limit; i++)
        {
            s+=i;
            sq_sum+=i*i;
        }
        cout << (s*s)-sq_sum << endl;
    }
    return 0;
}
