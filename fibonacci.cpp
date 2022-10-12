#include <bits/stdc++.h>
using namespace std;

long long int fibo(long long int n){
    if(n==1){
        return n-1;
    }
    else if(n==2){
        return n-1;
    }
    return fibo(n-1)+fibo(n-2);
}

int main() {
    long long int n;
    cin>>n;
    long long int fiboo=fibo(n);
    cout<<fiboo<<endl;
}