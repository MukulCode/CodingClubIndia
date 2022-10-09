#include <bits/stdc++.h>
using namespace std;

int main() {
	int tatab;
	cin>>tatab;
	while(tatab--){
	    
	        int w;
    cin>>w;
string s;
cin>>s;

    int n = s.length();
 
    
    char a[n + 1];
 

    strcpy(a, s.c_str());
   
sort(a,a+n);
if(s.length()<3){
    cout<<s<<endl;
}
else {
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
}
	}
	return 0;
}
