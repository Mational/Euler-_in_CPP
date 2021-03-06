#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

bool is_prime(int dane)
{
    for(int i=2;i*i<=dane;i++)
        if(dane%i==0)
            return false;
    return true;
}

string zamien(string s_sp, int p0, int in)
{
    s_sp[p0]=in+48;
    return s_sp;
}

void fun(string liczba, int p[], int ile)
{
    int wynik=10e6;
    int l_p=0;
    for(int n=0;n<10;n++)
    {
        string k_liczba=liczba;
        if(p[0]==0 && n==0)
            continue;
        for(int r=0;r<ile;r++)
            k_liczba=zamien(k_liczba,p[r],n);
        if(is_prime(stoi(k_liczba))==true)
        {
            l_p++;
            if(stoi(k_liczba)<wynik)
                wynik=stoi(k_liczba);
        }
    }
    if(l_p==8)
    {
        cout << "Liczba " << wynik << endl;
        /*cout << "Cyfry: " << ile << endl;
        for(int k=0;k<ile;k++)
            cout << p[k]+1 << endl;*/
        exit(0);
    }
    return;
}

void proces(string sp,int idl,int ij)
{
    int t[3]={0,0,0};
    for(t[0]=0;t[0]<idl-ij;t[0]++)
    {
        if( ij==1)
            fun(sp,t,ij);
        else
            for(t[1]=t[0]+1;t[1]<idl-ij+1;t[1]++)
            {
                if(ij==2)
                    fun(sp,t,ij);
                else
                    for(t[2]=t[1]+1;t[2]<idl-ij+2;t[2]++)
                        if(ij==3)
                            fun(sp,t,ij);
            }
    }
    return;
}

void uzupelnij(vector<int>&p,string sciezka)
{
    fstream plik;
    plik.open(sciezka,ios::in);
    int line;
    while(!plik.eof())
    {
        plik >> line;
        p.push_back(line);
    }
    return;
}

int main()
{
    vector<int>prime;
    uzupelnij(prime,"#51_pierwsze.txt");
    for(int i=0;i<prime.size();i++)
    {
        int dl=log10(prime[i])+1;
        for(int j=1;j<dl;j++)
            proces(to_string(prime[i]),dl,j);
    }
    return 0;
}

