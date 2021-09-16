#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_perfect_root(int inum)
{
    if((float)sqrt(inum)==(int)sqrt(inum))
        return true;
    return false;
}

bool is_period(vector<int>&vn, vector<int>&vd,vector<int>&va, int in, int id, int ia)
{
    for(int i=0;i<vn.size();i++)
        if(vn[i]==in && vd[i]==id && va[i]==ia)
            return true;
    return false;
}

bool program(int inumber)
{
    vector<int> numerators;
    vector<int> denominators;
    vector<int> a;
    int num1=1;
    int num2=0;
    int a2=floor(sqrt(inumber));
    int denum=-a2;

    while(true)
    {
        num2=-denum;
        denum=inumber-denum*denum;

        if((float)denum/num1==(int)denum/num1)
        {
            denum/=num1;
            num1=1;
        }

        num2*=num1;
        a2=(sqrt(inumber)+num2)/denum;
        num2-=(a2*denum);

        if(numerators.size()>0)
            if(is_period(numerators,denominators,a, num2, denum, a2) == true)
            {
                if(numerators.size()%2!=0)
                    return true;
                return false;
            }

        numerators.push_back(num2);
        denominators.push_back(denum);
        a.push_back(a2);

        num1=denum;
        denum=num2;
        num2=0;
    }
}

int main()
{
    int period=0;
    for(int i=2;i<=10000;i++)
    {
        if(is_perfect_root(i)==true)    continue;
        if(program(i)==true)            period++;
    }
    cout << "Answer: " << period << endl;
    return 0;
}

