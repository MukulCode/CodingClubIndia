#include<iostream>
using namespace std;
int preSum(int arr[],int n)
{
    int lsum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int tsum=0;
            for(int k=i;k<=j;k++)
            {
                tsum+=arr[k];
            }cout<<tsum<<" ";
            lsum=max(lsum,tsum);
        }
    }
    return lsum;
}
int main()
{
    int arr[]={1,2,3,4,5,-6,7,8,9,10};
    int n=sizeof(arr)/sizeof(int);
    cout<<"largest sum is "<<preSum(arr,n);
    return 0;

}