#include<iostream>
#include<bits/std++.h>
using namespace std;
int reverse(int arr[],int n)
{
    cout<<endl;
    cout<<"after reversing the array="<<endl;
    for(int i=n-1;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
}
 int singleNumber(int arr[]) 
 {
        int num=0;
        for(auto n:arr)
            num^=n;
        return num;
 }
        
int main()
{
    int arr[]={1,3,6,9,1,6,9,3,2};
    cout<<singleNumber<<endl;
    int n=sizeof(arr)/sizeof(int);
    
    int i;
    cout<<"before reversing ="<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }
    reverse(arr,10);
    return 0;
}