#include<iostream>
using namespace std;
bool isPrime(int num)
{
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int kp=0;
    for(int j=sum;j<1000;j++)
    {
        if(isPrime(j))
        {
            kp=j;
            break;
        }
    }
    cout<<kp-sum;
    
    return 0;
}