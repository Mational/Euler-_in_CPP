#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int number=0;
int prev_num=0;
int ile_pod_rzad=1;

void zczytaj(vector<int>&p,string sciezka)
{
    fstream plik;
    int dane;
    plik.open(sciezka,ios::in);
    while(!plik.eof())
    {
        plik >> dane;
        p.push_back(dane);
    }
    plik.close();
    return;
}

bool czy_pierwsza(int dane)
{
    for(int j=2;j*j<=dane;j++)
        if(dane%j==0)
            return false;
    return true;
}

bool czy_powtarza(vector<int>&w,int poz)
{
    if(poz==0)
        return true;
    for(int j=0;j<poz;j++)
        if(w[j]==w[poz])
            return false;
    return true;
}

bool czy_rozne(vector<int>&c)
{
    vector<int>r;
    for(int i=0;i<c.size();i++)
    {
        if(czy_powtarza(c,i)==true)
            r.push_back(i);
    }
    if(r.size()==4)
        return true;
    return false;
}

bool czy_cztery_r_czyn_pier(int iliczba,vector<int>&p)
{
    int tmp=iliczba;
    vector<int>czynniki_p;
    while(iliczba!=1)
    {
        int poz=0;
        while(p[poz]<=iliczba)
        {
            if(iliczba%p[poz]==0)
            {
                iliczba/=p[poz];
                czynniki_p.push_back(p[poz]);
                poz=0;
                break;
            }
            poz++;
        }
    }
    if(czy_rozne(czynniki_p)==true)
    {
        prev_num=number;
        number=tmp;
        if(number-prev_num==1)
        {
            ile_pod_rzad++;
            if(ile_pod_rzad==4)
                return true;
        }
        else
            ile_pod_rzad=1;
    }
    return false;
}

int main()
{
    vector<int>pierwsze;
    zczytaj(pierwsze,"#47_pierwsze.txt");
    int liczba=3;
    bool cztery_r=false;
    do
    {
        liczba++;
        cztery_r=czy_cztery_r_czyn_pier(liczba,pierwsze);
    }while(cztery_r==false);
    cout << "Liczba: " << liczba-3 << endl;
    return 0;
}
