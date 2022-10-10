#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
        }
        if(str[0]=='y' && str[1]=='e' && str[2]=='s')
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }
}