#include<bits/stdc++.h>
using namespace std;



int main(){
int tatab;
cin>>tatab;
while(tatab--){

    //so here we are taking long because it will store some long data in future
    long long int a,b;
    cin>>a>>b;
    if(a%2!=0 && b%2!=0){
        cout<<"NO"<<endl;
    }
    
    
    else if( a<2 || b<2) cout<<"NO"<<endl;
    
    
    
    else cout<<"YES"<<endl;
}



    return 0;
}
