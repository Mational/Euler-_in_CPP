#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int counter=0;
    for(int i=1;i<10;i++)
        for(int j=1;j<22;j++)
        {
            unsigned long long number=pow(i,j);
            if( (int)log10(number)+1 == j)
                counter++;
        }
    //Last number is just over 64 bits... so we add 1 to our counter
    cout << counter+1 << endl;
    return 0;
}
