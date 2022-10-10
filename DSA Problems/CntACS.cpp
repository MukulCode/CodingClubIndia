#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int pt;
        cin>>pt;
        if(pt>=100){
            if(pt%100<=(10-(pt/100)))
            cout<<((pt%100)+(pt/100))<<endl;
            else
            cout<<"-1"<<endl;
        }
        else{
            if(pt<=10)
            cout<<pt<<endl;
            else
            cout<<"-1"<<endl;
        }
    }
	// your code goes here
	return 0;
}
