#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int dzielniki(int n)
{
    int dziel=0;
    int sn = sqrt(n);
    for(int j=1;j<=sn;j++)
        if(n%j==0)
        {
            dziel++;
            if(n/j!=j && n/j!=1)
                dziel++;
        }
    return dziel;
}

long long program(int limit, vector<int>&v_dziel, vector<long long>&v_num)
{
    for(int i=0;i<v_dziel.size();i++)
        if(v_dziel[i]>limit)   return v_num[i];

    int i=v_num.size() + 1;
    long long sum = v_num[ v_num.size()-1] + i;

    do
    {
        v_num.push_back(sum);
        v_dziel.push_back(dzielniki(sum));
        sum += ++i;
    }while(v_dziel[v_dziel.size()-1]<=limit);

    return v_num[v_num.size()-1];
}

int main()
{
    int t;
    cin >> t;
    vector<int> v_dziel {0, 2, 4};
    vector<long long> v_num {1, 3, 6};

    for(int a0=0;a0<t;a0++)
    {
        int number;
        cin >> number;
        cout << program(number, v_dziel, v_num) << endl;
    }
    return 0;
}
