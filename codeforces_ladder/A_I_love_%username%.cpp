#include <bits/stdc++.h>>
using namespace std;
int main() {
  int n;
  cin>>n;
  int best,worst;
  cin>>best;
  worst=best;
  int count =0;
  while(--n){
    int a;
    cin>>a;
    if(a<worst){
      worst = a;
      count++;
    }
    if(a>best){
      best = a;
      count++;
    }
  }
  cout<<count<<"\n";
  return 0;


  }
