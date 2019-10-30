#include<bits/stdc++.h>
using namespace std;

unsigned long int small(unsigned long int array[], unsigned long int size)
{
    unsigned long int index = 0;
    for(unsigned long int i = 1; i < size; i++)
    {
        if(array[i] < array[index])
            index = i;
    }
    return index;
}

int testcase()
{
    unsigned long int i,n,s,ans=0,m;
    cin>>n;
    unsigned long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    s=n;
    if(n>1)
    {
    do{
        m=small(a,s);
        //cout<<m<<" "<<s<<endl;
        if(m==0)
        {
            if(a[s]<=a[m+1])
            {
                a[s]+=a[m];
                ans+=a[s];
                for(i=m;i<s;i++)
                {
                    a[i]=a[i+1];
                }
                s--;
            }
            else
            {
                a[m]+=a[m+1];
                ans+=a[m];
                for(i=m+1;i<s;i++)
                {
                    a[i]=a[i+1];
                }
                s--;
            }
        }
        else if(m==s-1)
        {
            if(a[m-1]<=a[0])
            {
                a[m-1]+=a[m];
                ans+=a[m-1];
                for(i=m;i<s;i++)
                {
                    a[i]=a[i+1];
                }
                s--;
            }
            else
            {
                a[m]+=a[0];
                ans+=a[m];
                for(i=0;i<s;i++)
                {
                    a[i]=a[i+1];
                }
                s--;
            }
        }
        else
        {
            if(a[m-1]<=a[m+1])
            {
                a[m-1]+=a[m];
                ans+=a[m-1];
                for(i=m;i<s;i++)
                {
                    a[i]=a[i+1];
                }
                s--;
            }
            else
            {
                a[m]+=a[m+1];
                ans+=a[m];
                for(i=m+1;i<s;i++)
                {
                    a[i]=a[i+1];
                }
                s--;
            }
        }
       /* for(i=0;i<s;i++)
        {
            cout<<"a["<<i<<"]="<<a[i]<<" ";
        }
        cout<<endl;*/
    }while(s>1);
        cout<<ans;
    }
    else{
        if(n<=0)
        {
            cout<<0;
        }
        else
        {
            cout<<a[0];
        }
    }
    /*for(i=0;i<s;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<" "<<s<<" "<<ans;*/
    return 0;
}

int main()
{
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        testcase();
        cout<<endl;
    }
    return 0;
}
