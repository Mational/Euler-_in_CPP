#include <iostream>
#include <vector>

using namespace std;

int const r=28125;

bool czy_liczna(int liczba)
{
    int sd=1;
    for(int i=2;i*i<=liczba;i++)
    {
        if(liczba%i==0)
        {
            sd+=i;
            if(liczba/i!=1 && liczba/i!=i)
                sd+=liczba/i;
        }
    }
    if(sd>liczba)
        return true;
    return false;
}

void sumuj(vector<int>&l,bool b[])
{
    int poz;
    for(int i=0;i<l.size();i++)
    {
        for(int j=i;j<l.size();j++)
        {
            poz=l[i]+l[j];
            if(poz<r)
                b[poz]=true;
        }
    }
    return;
}

int main()
{
    long long s=0;
    vector<int>liczne;
    bool bliczne[r];

    //zerowanie tablicy bliczne
    for(int i=0;i<r;i++)
        bliczne[i]=false;

    //sprawdzanie jakie liczby sa liczne
    for(int n=1;n<=r;n++)
        if(czy_liczna(n)==true)
            liczne.push_back(n);

    //wyznaczanie liczb, ktore sa suma liczb licznych
    sumuj(liczne,bliczne);

    //sumowanie liczb niebedacych suma liczb licznych
    for(int i=0;i<r;i++)
        if(bliczne[i]==false)
            s+=i;

    cout << "Suma: " << s << endl;
    return 0;
}
