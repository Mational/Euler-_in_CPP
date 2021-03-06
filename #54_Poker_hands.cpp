#include <iostream>
#include <fstream>

using namespace std;

const char znaki[13]={'A','K','Q','J','T','9','8','7','6','5','4','3','2'};
int wgracz1=0;
int wgracz2=0;
int par2;

int find_char(char v[],int poz)
{
    for(int k=0;k<13;k++)
        if(v[poz]==znaki[k])
            return k;
}

void sorting(char values[],char colors[])
{
    int n=0;
    int k=4;
    start:
    while(k>=0)
        for(int i=0;i<13;i++)
            for(int j=0;j<=k;j++)
                if(values[j]==znaki[i])
                {
                    swap(values[j],values[k]);
                    swap(colors[j],colors[k]);
                    k--;
                    goto start;
                }
    return;
}

bool same_suit(char c[])
{
    if(c[0]==c[1]&&c[1]==c[2]&&c[2]==c[3]&&c[3]==c[4])
        return true;
    return false;
}

bool con_values(char v[])
{
    int w;
    w=find_char(v,4);
    for(int i=4;i>=0;i--)
    {
        if(v[i]==znaki[w])
        {
            w++;
            continue;
        }
        return false;
    }
    return true;
}

int pairs(char v[])
{
    int pars[5]={0,0,0,0,0};
    for(int i=0;i<5;i++)
    {
        int para=1;
        for(int j=i-1;j>=0;j--)
            if(v[j]==v[i])
                goto next;
        for(int k=i+1;k<5;k++)
            if(v[i]==v[k])
                para++;
        pars[i]=para;
        next:;
    }
    int p[3]={0,0,0};
    par2=13;
    for(int i=0;i<5;i++)
    {
        if(pars[i]==2)
        {
            par2=find_char(v,i);
            p[0]++;
        }
        else if(pars[i]==3)
            p[1]++;
        else if(pars[i]==4)
            p[2]++;
    }
    if(p[1]==1 && p[0]==1)
        return 4;
    if(p[0]==1)
        return 1;
    if(p[0]==2)
        return 2;
    if(p[1]==1)
        return 3;
    if(p[2]==1)
        return 5;
    return 0;
}

int ranked_hand(char v[],char c[])
{
    if(con_values(v)==true && v[4]=='A' && same_suit(c)==true)  return 10;
    if(same_suit(c)==true && con_values(v)==true)               return 9;
    if(pairs(v)==5)                                             return 8;
    if(pairs(v)==4)                                             return 7;
    if(same_suit(c)==true)                                      return 6;
    if(con_values(v)==true)                                     return 5;
    if(pairs(v)==3)                                             return 4;
    if(pairs(v)==2)                                             return 3;
    if(pairs(v)==1)                                             return 2;
    return 1;
}

void max_value(char vgracz1[],char vgracz2[])
{
    for(int i=4;i>=0;i++)
        if(vgracz1[i]!=vgracz2[i])
        {
            int k1,k2;
            k1=find_char(vgracz1,i);
            k2=find_char(vgracz2,i);
            if(k1<k2)   wgracz1++;
            else        wgracz2++;
            return;
        }
}

void zadanie(char vgracz1[],char cgracz1[],char vgracz2[],char cgracz2[])
{
    sorting(vgracz1,cgracz1);
    sorting(vgracz2,cgracz2);
    int rhgracz1 = ranked_hand(vgracz1,cgracz1);
    int g1par2=par2;
    int rhgracz2 = ranked_hand(vgracz2,cgracz2);
    int g2par2=par2;
    if(rhgracz1>rhgracz2)
        wgracz1++;
    else if(rhgracz2 > rhgracz1)
        wgracz2++;
    else if(rhgracz1==9 || rhgracz1==6 || rhgracz1==5 || rhgracz1==1)
        max_value(vgracz1,vgracz2);
    else if(rhgracz1==2)
    {
        if(g1par2<g2par2)       wgracz1++;
        else if(g1par2>g2par2)  wgracz2++;
        else                    max_value(vgracz1,vgracz2);
    }
    return;
}

int main()
{
    char vgracz1[5];
    char vgracz2[5];
    char cgracz1[5];
    char cgracz2[5];
    fstream plik;
    plik.open("#54_poker.txt",ios::in);
    for(int j=0;j<1000;j++)
    {
        for(int i=0;i<5;i++)
        {
            plik >> vgracz1[i];
            plik >> cgracz1[i];
        }
        for(int i=0;i<5;i++)
        {
            plik >> vgracz2[i];
            plik >> cgracz2[i];
        }
        zadanie(vgracz1,cgracz1,vgracz2,cgracz2);
    }
    cout << "WGRACZ1: " << wgracz1 << endl;
    //cout << "WGRACZ2: " << wgracz2 << endl;
    //cout << "Nierozstrzygniete: " << 1000-(wgracz1+wgracz2) << endl;
    return 0;
}
