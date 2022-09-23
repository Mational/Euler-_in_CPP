#include <iostream>

using namespace std;

int collatz(long long liczba)
{
    int lancuch = 0;
    while(liczba != 1)
    {
        lancuch++;
        liczba = (liczba%2==0)?liczba/2:liczba*3+1;
    }
    return lancuch;
}

int main()
{
    int t;
    cin >> t;
    for(int a0=0;a0<t;a0++)
    {
        int length;
        cin >> length;
        int dl;
        int maks_lancuch=0;
        int max_liczba=0;
        for(int i=length;i>=1;i--)
        {
            dl=collatz(i);
            if(dl>maks_lancuch)
            {
                maks_lancuch=dl;
                max_liczba=i;
            }
        }
        cout << max_liczba << endl;
    }
    return 0;
}
