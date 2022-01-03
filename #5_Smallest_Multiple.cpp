#include <iostream>

using namespace std;

int nwd(int liczba, int a)                      //wyliczanie NWD
{
    while(true)
    {
        if(liczba>a)    swap(liczba,a);
        if(liczba==0)   break;
        int tmp=liczba;
        liczba=a%liczba;
        a=tmp;
    }
    return a;

}

int main()
{
    int t;
    cin >> t;
    for(int a0=0;a0<t;a0++)
    {
        int i;
        cin >> i;
        int answer=1;
        for(int j=2; j<=i;j++)
            answer=(answer*j)/nwd(j,answer);  //wyszukiwanie NWW poprzez zale¿noœæ z NWD
        cout << answer << endl;
    }
    return 0;
}
