#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if((x+y)%4==0 ||(x+y-1)%4==0)
        cout<<"Alice"<<endl;
        else
        cout<<"Bob"<<endl;
    }
	// your code goes here
	return 0;
}
