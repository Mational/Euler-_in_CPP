#include <iostream>
#include <fstream>

using namespace std;

void read(string path,string num[])
{
    fstream file;
    file.open(path,ios::in);
    for(int i=0;i<100;i++)
    {
        file >> num[i];
    }
    file.close();
    return;
}

string add(string r,string n)
{
    if(r.size()<n.size())
    {
        swap(r,n);
    }
    int r_pos=r.size()-1;
    int n_pos=n.size()-1;
    int tmp=0;
    while(r_pos>=0)
    {
        int r_num=r[r_pos]-48;
        int n_num;
        if(n_pos>=0)
        {
            n_num=n[n_pos]-48;
        }
        else
        {
            n_num=0;
        }
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

void calculations(string num[])
{
    string result=num[0];
    string sres;
    for(int i=1;i<100;i++)
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
    string numbers[100];
    read("#13_numbers.txt",numbers);
    calculations(numbers);
    return 0;
}
