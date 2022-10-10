#include<iostream>
using namespace std;
int fact(int t)
{
    if(t<=1) 
    return 1;

    return t*fact(t-1);
}
int nCr(int n,int r)
{
    int nCr;
    if(r==0||n==r){
        nCr=1;
    }
    else{
        nCr=fact(n)/(fact(n-r)*fact(r));
    }
    return nCr;
}
int main()
{
    int n;
    cin>>n;
    int r;
    cin>>r;
    cout<<nCr(n,r);
    return 0;
}