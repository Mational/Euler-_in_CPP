#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int a0=0;a0<t;a0++)
    {
        int n;
        cin >> n;
        n--;
        long three=n/3;
        long five=n/5;
        long fifteen=n/15;
        long long answer=0;
        answer += (three*3+3)*three/2;
        answer += (five*5+5)*five/2;
        answer -= (fifteen*15+15)*fifteen/2;
        cout << answer << endl;
    }
    return 0;
}
