#include<iostream>
using namespace std;
int subarraySum(int arr[],int n)
{
    int lsum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int tsum=0;
            for(int k=i;k<=j;k++)
            {
                cout<<arr[k]<<" ";
                tsum+=arr[k];
            }cout<<" sum="<<tsum; cout<<endl;
            if(tsum>lsum)
            lsum=tsum;
        }
    }
    cout<<"largest sum of subarray="<<lsum<<endl;
}
int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    subarraySum(arr,n);
    return 0;
}