#include <iostream>
#include <vector>
#include <string>

using namespace std;

void najwiekszy_lancuch( vector <int>&d, int k, int n)
{
    long long maks=0;
    for( int i=0; i<=n; i++ )
    {
        long long iloczyn=1;
        for( int j=0; j<k; j++ )
            iloczyn*=d[i+j];
        if( iloczyn>maks )
            maks=iloczyn;
    }
    cout << maks << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        vector <int> dane;
        for( int i=0; i<n; i++ )
        {
            string tekst="";
            tekst.insert(0,num,i,1);
            int j=stoi(tekst);
            dane.push_back(j);
        }
        najwiekszy_lancuch(dane, k, n);
    }
    return 0;
}
