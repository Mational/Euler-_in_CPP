#include <iostream>
#include <fstream>

using namespace std;

char keys[3];

int licz(string t)
{
    int s=0;
    for(int j=0;j<t.size();j++)
        s+=(int)t[j];
    return s;
}

void program(string sciezka)
{
    int n;
    char letter;
    char en;
    int i=0;
    fstream plik;
    string text="";
    plik.open(sciezka,ios::in);
    while(!plik.eof())
    {
        plik >> n;
        letter=(char)n;
        en=letter^keys[i%3];
        if( en>='a' && en<='z')
            text+=en;
        else if(en>='A' && en<=']')
            text+=en;
        else if(en>='+' && en<=';')
            text+=en;
        else if(en>=' ' && en<='"')
            text+=en;
        else if((int)en==39 || en=='?' || en=='(' || en==')')
            text+=en;
        else
            return;
        i++;
    }
    //cout << text << endl;
    int wynik=licz(text);
    cout << "Wynik: " << wynik << endl;
    return;
}

int main()
{
    for( char p1='a'; p1<='z';p1++)
    {
        keys[0]=p1;
        for( char p2='a'; p2<='z';p2++)
        {
            keys[1]=p2;
            for( char p3='a'; p3<='z';p3++)
            {
                keys[2]=p3;
                program("#59_messege.txt");
            }
        }
    }
    return 0;
}
