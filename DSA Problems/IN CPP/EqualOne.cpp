
#include<iostream>
using namespace std;
int main()
{
    int t;
 cin>>t;
 while(t--)
 {
    int x,y;
 cin>>x>>y;
 int count=0;
 if(x<y)
 {
 x=x+10;
     while(x<y)
     {
         ++count;
         x+=10;
     }
 }
 if(x>y)
 {
 
     while(x>y)
     {
         count++;
         
         x-=10;
     }
 }
 cout<<count<<"\n";
    
 }}