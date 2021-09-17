#include <iostream>

using namespace std;

const int length=200001;

int main()
{
    int t;
    cin >> t;
    for(int a0=0;a0<t;a0++)
    {
        int limit;
        cin >> limit;
        int liczba=1, l_pierwsze=0;
        bool numbers[length]={1,1};

        int i=2;
        while(l_pierwsze!=limit)
        {
            if(numbers[i]==0)
            {
                l_pierwsze++;
                for(int j=i+i;j<length;j+=i)
                    numbers[j]=1;
            }
            i++;
        }
        cout << i-1 << endl;
    }
    return 0;
}
