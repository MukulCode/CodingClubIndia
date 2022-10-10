#include<iostream>
using namespace std;
int lSum(int arr[],int n)
{
    int ls=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int s=0;
            for(int k=i;k<=j;k++)
            {
                s+=arr[k];
            } 
            cout<<s<<",";
            if(s>ls)
            {ls=s;}
            //cout<<endl;
        }
    }cout<<endl;
    cout<<"largest sum equals to "<<ls<<endl;
}
int main()
{
    int arr[]={-1,-2,-3,-4};
    int n=sizeof(arr)/sizeof(int);
    lSum(arr,n);
    return 0;
}