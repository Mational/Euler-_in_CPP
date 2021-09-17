#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int maks=0;

bool is_palindrom(int d)
{
    string pal=to_string(d);
    reverse(pal.begin(),pal.end());
    int rd=stoi(pal);
    if(rd==d)
        return true;
    return false;
}

void program(int l)
{
    for(l=l-1;l>=101101;l--)
        if(is_palindrom(l)==true)
            for(int i=100;i<1000;i++)
                if(l%i==0 && (int)log10(l/i)+1==3)
                {
                    cout << l << endl;
                    return;
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
