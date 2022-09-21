#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool done=false;
long long answer=0;
vector<int> numbers;
vector<int> counts;

bool is_perm(long long n1, long long n2)
{
    int tab[10]={0,0,0,0,0,0,0,0,0,0};
    while(n1>0)
    {
        tab[n1%10]++;
        n1/=10;
    }
    while(n2>0)
    {
        tab[n2%10]--;
        n2/=10;
    }
    for(int i=0;i<10;i++)
        if(tab[i]!=0)
            return false;
    return true;
}

void is_cubic_perm(int n)
{
    if(numbers.size()==0)
    {
        numbers.push_back(n);
        counts.push_back(1);
    }
    else
    {
        for(int i=0;i<numbers.size();i++)
        {
            if(is_perm(pow(numbers[i],3),pow(n,3))==true)
            {
                counts[i]++;
                if(counts[i]==5)
                {
                    done=true;
                    answer=pow(numbers[i],3);
                    return;
                }
            }
        }
        numbers.push_back(n);
        counts.push_back(1);
    }
}

int main()
{
    for(int i=345;done==false;i++)
        is_cubic_perm(i);
    cout << "Answer: " << answer << endl;
    return 0;
}
