#include <iostream>
#include <windows.h>

using namespace std;

string dodaj(string c, string d)
{
    int pc=c.size()-1;
    string w="";
    string cyf;
    int pd=d.size()-1;
    int p=0;
    while(pc>=0 || pd>=0)
    {
        int cc,cd,w_s;
        if(pc>=0)   cc=c[pc]-48;    else    cc=0;
        if(pd>=0)   cd=d[pd]-48;    else    cc=0;
        w_s=cc+cd+p;
        cyf=to_string(w_s%10);
        w.insert(0,cyf,0,1);
        p=w_s/10;
        pc--;pd--;
    }
    if(p)  w="1"+w;
    return w;
}

string mnozenie(string a,string b)
{
    string wynik=a;
    string wiersz;
    int pa=a.size()-1;
    int pb=b.size()-1;
    int p, w_p, ca, cb, pr=0;
    for(int i=pb;i>=0;i--)
    {
        wiersz="";
        p=0;
        cb=b[i]-48;
        for(int k=pa;k>=0;k--)
        {
            ca=a[k]-48;
            w_p=(ca*cb)+p;
            wiersz.insert(0,to_string(w_p%10),0,1);
            p=w_p/10;
        }
        if(i==0 && p!=0)
            wiersz=to_string(p)+wiersz;
        wynik=wiersz;
        pr++;
    }
    return wynik;
}

int main()
{
    string wynik="1";
    int suma=0;
    for(int j=1;j<=100;j++)
    {
        if(j<10)
            wynik=mnozenie(wynik,to_string(j));
        else
        {
            string zap=wynik;
            wynik=mnozenie(wynik,to_string(j/10))+"0";
            if(j%10!=0)
            {
                zap=mnozenie(zap,to_string(j%10));
                wynik=dodaj(zap,wynik);
            }
        }
    }
    wynik+="0";
    //cout << "100! = " << wynik << endl;
    for(int i=0;i<wynik.size();i++)
        suma+=wynik[i]-48;
    cout << "\nSuma cyfr: " << suma << endl;
    return 0;
}
