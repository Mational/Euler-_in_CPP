#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int a0=0;a0<t;a0++)
    {
        long limit;
        cin >> limit;
        long a=1, b=1, s=0;
        while(b<=limit)
        {
            if( b%2==0 )
                s+=b;
            b+=a;
            a=b-a;
        }
        cout << s << endl;
    }
    return 0;
}
