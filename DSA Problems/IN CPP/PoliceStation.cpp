#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(int N, int a, vector<int> x) 
    {
        sort(x.begin(),x.end());
        int k=x.size()-1;
        int s=0;
        int c=0;
        for(int i=k;c<=2;i--)
        {
            if(x[k]!=x[k-1]) 
            {
                s+=(abs(x[k]-a));
                c++;
                
            }
            else
            {
                s+=(abs(x[k]-a));
            }
                
            
        }
        return s;
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {

        int N, a;
        cin >> N >> a;


        vector<int> x(N);
        for (int i = 0; i < N; i++)
            cin >> x[i];

        Solution ob;
        cout << ob.solve(N, a, x) << "\n";
    }
    return 0;
}
  // } Driver Code Ends