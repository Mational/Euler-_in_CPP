#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void poziomo(int t[20][20],long long&maks)
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<17;j++)
        {
            long long iloczyn=1;
            for(int z=0;z<4;z++)
                iloczyn*=t[i][j+z];
            if(iloczyn>maks)
                maks=iloczyn;
        }
    }
    return;
}

void pionowo(int t[20][20],long long&maks)
{
    for(int j=0;j<20;j++)
    {
        for(int i=0;i<17;i++)
        {
            long long iloczyn=1;
            for(int z=0;z<4;z++)
                iloczyn*=t[i+z][j];
            if(iloczyn>maks)
                maks=iloczyn;
        }
    }
    return;
}

void przekatna_p(int t[20][20],long long&maks)
{
    for(int i=0;i<17;i++)
    {
        for(int j=0;j<17;j++)
        {
            long long iloczyn=1;
            for(int z=0;z<4;z++)
                iloczyn*=t[i+z][j+z];
            if(iloczyn>maks)
                maks=iloczyn;
        }
    }
    return;
}

void przekatna_l(int t[20][20],long long&maks)
{
    for(int i=0;i<17;i++)
    {
        for(int j=19;j>=3;j--)
        {
            long long iloczyn=1;
            for(int z=0;z<4;z++)
                iloczyn*=t[i+z][j-z];
            if(iloczyn>maks)
                maks=iloczyn;
        }
    }
    return;
}

int main()
{
    long long maks=0;
    int tab[20][20];
    for(int a0=0;a0<20;a0++)
        for(int a1=0;a1<20;a1++)
            cin >> tab[a0][a1];
    poziomo(tab,maks);
    pionowo(tab,maks);
    przekatna_p(tab,maks);
    przekatna_l(tab,maks);
    cout << maks << endl;
    return 0;
}
