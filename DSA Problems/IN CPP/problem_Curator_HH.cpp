#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    string v1;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>v1;
        for(int i=0;i<v1.size()-1;i+=2)
    {
        cout<<v1[i];
    }
    cout<<" ";
        for(int i=1;i<=v1.size()-1;i+=2)
    {
        cout<<v1[i];
    }
    cout<<endl;
    }
    return 0;
}
