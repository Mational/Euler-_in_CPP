#include <iostream>
#include <fstream>

using namespace std;

int const r=15;

void zeruj(int tab[r][r])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<=i;j++)
            tab[i][j]=0;
    }
    return;
}

void czytaj(int tab[r][r],string sciezka)
{
    fstream plik;
    plik.open(sciezka,ios::in);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<=i;j++)
        {
            plik >> tab[i][j];
        }
    }
    plik.close();
    return;
}

void wypisz(int tab[r][r])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<=i;j++)
            cout << tab[i][j] << " ";
        cout << endl;
    }
    return;
}

int droga(int t[r][r], int i,int j,int s)
{
    if(i<r-2)
    {
        int lm_l=t[i+1][j]+t[i+2][j];
        int lm_p=t[i+1][j]+t[i+2][j+1];
        int lp_l=t[i+1][j+1]+t[i+2][j+1];
        int lp_p=t[i+1][j+1]+t[i+2][j+2];
        int pm,lm;

        if(lm_l>lm_p)   lm=lm_l;
        else            lm=lm_p;

        if(lp_l>lp_p)   pm=lp_l;
        else            pm=lp_p;

        if(lm>pm)   return droga(t,i+1,j,s+t[i][j]);
        return droga(t,i+1,j+1,s+t[i][j]);
    }
    if(i==r-2)
    {
        if(t[i+1][j]>t[i+1][j+1])   return droga(t,i+1,j,s+t[i][j]);
        return droga(t,i+1,j+1,s+t[i][j]);
    }
    if(i==r-1)   return s+t[i][j];
}

int main()
{
    int tab[r][r];
    zeruj(tab);
    czytaj(tab,"#18_dane.txt");
    //wypisz(tab);
    int suma=droga(tab,0,0,0);
    cout << suma << endl;
    return 0;
}
