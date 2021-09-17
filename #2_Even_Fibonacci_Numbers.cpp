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
        long a=1, b=1, c, s=0;
        while(b<=limit)
        {
            if( b%2==0 )
                s+=b;
            c=b;
            b+=a;
            a=c;
        }
        cout << s << endl;
    }
    return 0;
}
