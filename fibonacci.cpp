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

vector<int>dp;

//Added memoization for faster execution
int Fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if(dp[n] != -1) return dp[n];

    return dp[n] = Fib(n-1) + Fib(n-2);
}


int main(){
    int n,j=0;
    cout << "Enter the total number of terms:";
    cin >> n;

    dp = vector<int>(n+1);
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
            int r = Fib(j);
            cout << r << " ";
            j++;
    }
}

