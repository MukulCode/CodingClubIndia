#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int setCount(int n)
{
    int cnt=0;
    while(n)
    {
            cnt+= n&1;
            n = n>>1;
    }
    return cnt;

}

int main()
{
    int  n;
    cin>>n;
   
    cout<<setCount(n)<<endl;;
    cout<<(n>>1);
    return 0;
}