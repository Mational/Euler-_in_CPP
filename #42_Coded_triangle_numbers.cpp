#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

void czytaj(vector <string>&w,string sciezka)
{
    fstream plik;
    string word;
    plik.open(sciezka,ios::in);
    while(!plik.eof() )
    {
        plik >> word;
        w.push_back(word);
    }
    plik.close();
    return;
}

bool czy_triangle(string word)
{
    int r=word.size();
    int suma=0;
    for(int n=0;n<r;n++)
        suma+=word[n]-64;
    float tr=(-1+sqrt(1+8*suma))/2;
    if(tr-(int)tr==0)
        return true;
    return false;;
}

int main()
{
    vector <string> words;
    int ilosc=0;
    czytaj(words,"#42_words.txt");
    for(int i=0;i<words.size();i++)
        if( czy_triangle(words[i])==true )
            ilosc++;
    cout << "Ilosc: " << ilosc << endl;
    return 0;
}
