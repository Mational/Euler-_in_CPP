#include <iostream>

using namespace std;

long long program(int n)
{
    long long wynik = -1;
    int a, b, c;
    for(c=n;c>n/3;c--)
        for(b=c-1;b+c<n;b--)
        {
            a = n-(b+c);
            if(a>=b || a+b+c<n) break;
            if((a*a)+(b*b)==(c*c) && a*b*c>wynik)
                wynik = a*b*c;
        }
    return wynik;
}

int main()
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;
        cout << program(n) << endl;
    }
    return 0;
}
