// The command consists string of "G", "()" and/or "(al)" in some order
// The code will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al".
// The interpreted strings are then concatenated in the original order.
// return the interpretation of command.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s,final="";
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='G')
        final.push_back('G');
        else if(s[i]=='(' && s[i+1]==')'){
            i++;
            final.push_back('o');
        }
        else if(s[i]=='(' && s[i+1]=='a'){
            i=i+3;
            final.push_back('a');
            final.push_back('l');
        }
    }
    cout<<final<<endl;
}