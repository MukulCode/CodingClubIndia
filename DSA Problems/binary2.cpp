#include<iostream>
using namespace std;
int search(int arr[],int n,int key)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        return mid;
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(int);
   
    if(search(arr,n,6)==-1)
    {cout<<"not found"<<endl;}
    else{cout<<"found at "<<search(arr,n,6)+1<<endl;}
    return 0;
}