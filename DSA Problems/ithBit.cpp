#include<iostream>
void ithbit(int &n,int p)
{
    int mask=n>>p;
    n=(mask&1) > 0 ? 1:0;
    
}
int main()
{                           //13=1101
    int n=13;                
    int p;
    std::cin>>p;
    ithbit(n,p);
    std::cout<<n;
    return 0;
}