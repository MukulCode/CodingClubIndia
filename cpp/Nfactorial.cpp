#include<iostream>
using namespace std;
int fac(int n){
    if(n==1){
        return 1;
    }
    return n*fac(n-1);
}
int main(){
    int n;
    cout<<"Enter the value of N : ";
    cin>>n;
    cout<<"Result is : "<<fac(n); 
}