#include<bits/stdc++.h>
#define int long long int
using namespace std;
bool check(vector<string> &kp int k){
    for(int i=0;i<kp[k].size();i++){
        string k1=kp[k];
        k1.erase(i+1,k1.size()i-1);
        string k2=kp[i];
        k2.erase(0,i+1)
        if(find(kp.begin(),kp.end(),k1)!=kp.end() && find(kp.begin(),kp.end(),k2)!=kp.end()){
            return true;
        }
    }
    return false;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string>kp;
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            kp.push_back(str);
        }
vector<int>result;
for(int i=0;i<n;i++){
    result.push_back(check(kp,i));
}
for(auto &ele : result)
{
    cout<<ele;
}
cout<<endl;
        
    }
}