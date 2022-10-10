#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
   // int r=0;
    //int a[t];
    while(t--)
    {
        int n;
         cin>>n;
        int e=0,o=0;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]%2==0)
            e++;
            else
            o++;
        }
        if(o<e)
        cout<<o<<endl;
        else
        cout<<e<<endl;
 
            
    }
   
    
 
}