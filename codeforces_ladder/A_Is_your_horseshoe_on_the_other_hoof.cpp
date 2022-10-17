#include <bits/stdc++.h>>
using namespace std;

int main() {
	set<int> s;
  int k,n=4;
  while(n--){
    cin>>k;
    s.insert(k);
  }
  cout<<4-s.size()<<"\n";
	return 0;
}