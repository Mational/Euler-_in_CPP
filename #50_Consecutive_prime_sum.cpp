#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int below=1000000;

void uzupelnij(vector<int>&p ,string sciezka)
{
    fstream plik;
    int n;
    plik.open(sciezka,ios::in);
    while(!plik.eof())
    {
        plik >> n;
        p.push_back(n);
    }
    return;
}

bool is_prime(int n)
{
    for(int j=2;j*j<=n;j++)
        if(n%j==0)
            return false;
        return true;
}

int main()
{
    vector<int>pierwsze;
    int maks_c=0;
    int l_c=0;
    uzupelnij(pierwsze,"#50_pierwsze.txt");
    for(int k=0;pierwsze[k]<below;k++)
    {
        int maks=0;
        int sum=0;
        int p_l=0;
        int l=0;
        for(int i=k;i<pierwsze.size();i++)
        {
            p_l++;
            sum+=pierwsze[i];
            if(sum>=below)
                break;
            if(is_prime(sum)==true && maks<sum)
            {
                l=p_l;
                maks=sum;
            }
        }
        if(l>l_c)
        {
            l_c=l;
            maks_c=maks;
        }
        else if(l_c==l)
            if(maks>maks_c)
                maks_c=maks;
    }
    cout << "Prime: " << maks_c << endl;
    //cout << "Terms: " << l_c << endl;
    return 0;
}
