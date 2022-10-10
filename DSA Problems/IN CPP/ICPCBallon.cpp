#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
       int n;
       cin>>n;
        unordered_map<char,int>kp;
        for(int i=0;i<n;i++)
        {
            char k;cin>>k;kp[k]++;
        }
        int result=0;
        for(auto x:kp)
        {
            int k1=(x.second-1);
            int k2=2;
            result+=k1+k2;
        }
        cout<<result<<endl;
    }
}