#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>kp;
        for(int i=0;i<n;i++)
        {
            int v;
            cin>>v;
            kp.push_back(v);
        }
        for(int i=0;i<n;i++)
        {
            int l;
            cin>>l;
            string s;
            cin>>s;
            for(int j=0;j<l;j++)
            {
                if(s[j]=='U'){
                    if(kp[i]==0){
                        kp[i]=9;
                    }
                    else{
                        kp[i]-=1;
                    }
                }
                else if(s[j]=='D'){
                    kp[i]=(kp[i]+1)%10;
                }

            }
        }
        for(auto &ele:kp){
            cout<<ele<<" ";
        }cout<<endl;
    }
    return 0;
}