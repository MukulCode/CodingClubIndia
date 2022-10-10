#include<iostream>
#include<algorithm>
#include<vector>
int isoddeven(int n)
{
    if(n&1)
    return true;
    else
    return false;
 
}

int main()
{
    int  n;
    std::cin>>n;
    int x=isoddeven(n);
    if(x==1)
    std::cout<<"odd";
    if(x==0)
    std::cout<<"even";
    return 0;
}