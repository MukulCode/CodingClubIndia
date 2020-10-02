#include<bits/stdc++.h>
using namespace std;
string place(int flag,int c,int d){
        string ans;
        for(int i=0;i<(c+d);i++){
            if(flag==0){
                ans+='d';
                flag=1;
            }else{
                ans+='c';
                flag=0;
            }
        }
        return ans;
}
int match(string s,string s1){
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=s1[i]){
            count++;
        }
    }
    return count;
}
int main() {

	string s;
	cin>>s;
	int c=0,d=0;
	for(int i=0;i<s.length();i++){
        if(s[i]=='c'){
            c++;
        }else{
            d++;
        }
	
	}
	if(abs(c-d)>1){
        cout<<"-1"<<endl;
        return 0;
	}
	int flag=0;
	if(c>d){
        flag=1;
	}

	string s1=place(flag,c,d);

	int a=match(s,s1);
	string s2;
	int b;
	if(c==d){
        flag=1;
        s2=place(flag,c,d);
        b=match(s,s2);

	}
	cout<<a<<" "<<b<<endl;
	cout<<min(a,b)/2<<endl;

	return 0;
}
