// Question
// https://codeforces.com/problemset/problem/1550/B

// Approach
// https://www.youtube.com/watch?v=GXmMYBEA-7M&ab_channel=HiteshTripathi

// similar problem
// https://www.geeksforgeeks.org/minimum-removal-of-consecutive-similar-characters-required-to-empty-a-binary-string/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        int count=0;
        if(b>=0){
            cout<<(a+b)*n<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i]!=s[i+1]) count++;
            }
            cout<<a*n + b*(count/2 + 1)<<endl;
        }
    }
}