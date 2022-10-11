#include <bits/stdc++.h>>
using namespace std;
int main() {
  int n;
  cin>>n;

  int a,b,c=0,m=0;
  while(n--){
    cin>>a>>b;
    c = c-a;
    c = c+b;

    if(c>m){
      m = c;
    }
  }
  cout<<m<<"\n";
  return 0;


  }
