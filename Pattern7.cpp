/* 
     *
    ***
   *****
    ***
     *
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i=1;
    while(i<=(n/2)+1)
    {
        int k=1;
        while (k<=(n/2)+1-i)
        {
            cout<<" ";
            k=k+1;
        }
        
        int j=1;
        while(j<=(2*i)-1)
        {
            cout<<"*";
            j=j+1;
        }
        cout<<endl;
        i++;
    }

    i=1;
    while(i<=n/2)
    {
        int k=1;
        while(k<=i)
        {
            cout<<" ";
            k++;
        }

        int j=2*((n/2)-i+1)-1;
        while(j>=1)
        {
            cout<<"*";
            j--;
        }
        cout<<endl;
        i++;
    }
}
