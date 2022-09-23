#include <iostream>

using namespace std;

string add(string r,string n)
{
    if(r.size()<n.size())
        swap(r,n);

    int r_pos=r.size()-1;
    int n_pos=n.size()-1;
    int tmp=0;

    while(r_pos>=0)
    {
        int r_num=r[r_pos]-48;
        int n_num;

        if(n_pos>=0)     n_num=n[n_pos]-48;
        else            n_num=0;

        int outcome=r_num+n_num+tmp;
        r[r_pos]=(outcome%10)+48;
        tmp=outcome/10;
        n_pos--;
        r_pos--;
    }

    if(tmp>0)
    {
        string stmp=to_string(tmp);
        r=stmp+r;
    }
    return r;
}

void calculations(string num[], int t)
{
    string result=num[0];
    string sres;
    for(int i=1;i<t;i++)
    {
        sres=add(result,num[i]);
        result=sres;
    }
    result.erase(10);
    cout << result << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    string numbers[t];
    for(int a0=0; a0<t;a0++)
        cin >> numbers[a0];

    calculations(numbers, t);
    return 0;
}
