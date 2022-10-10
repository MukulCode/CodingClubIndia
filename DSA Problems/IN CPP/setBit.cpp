#include<iostream>
using namespace std;
void set(int &n,int p)
{
    int mask=1;
    n=n|(mask<<p);

}
int main()
{
    int n=5,p=3;
    cout<<set(n,p);
    return 0;
}