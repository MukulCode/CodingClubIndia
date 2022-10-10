#include<iostream>
using namespace std;
/*void ithbit(int &n,int p)
{
    int mask=n>>p;
    n=(mask&1) > 0 ? 1:0;
    
}*/
//void equal()
int add(int n,int p)
{
    int c;
    c=n|p;
    return c;
    

}
int main()
{                           
    int n=2;
    int p=2;
    cout<<add(n,p);
    //std::cin>>p;
    //ithbit(n,p);
    //std::cout<<n;
    return 0;
}