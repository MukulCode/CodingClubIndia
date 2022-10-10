//to reverse array of given data using two poiter approach
#include<iostream>
using namespace std;
void reverseArray(int arr[],int n)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int temp= arr[s];
        arr[s]= arr[e];
        arr[e]=temp;
        s++;
        e--;
    }
    cout<<"after reversing"<<endl;
    for(int i=0;i<n;i++)
    {
    cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int k=sizeof(arr)/sizeof(int);
    cout<<"before reversing="<<endl;
     for(int i=0;i<k;i++)
    {
    cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverseArray(arr,k);
    return 0;
}