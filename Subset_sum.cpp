#include<iostream>
using namespace std;

    bool subsetsum_DP(int a[],int n, int sum)
    {
        bool dp[n+1][sum+1];
        int i,j;
      
        for(i=0;i<=n;i++)
            dp[i][0]=true;
        
        for(j=1;j<=sum;j++)
            dp[0][j]=false;
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=sum;j++)
            {
                if(dp[i-1][j]==true)
                    dp[i][j]=true;
                else
                {
                    if(a[i-1]>j)
                        dp[i][j]=false;
                    else
                        dp[i][j]=dp[i-1][j-a[i-1]];
                }
            }
        }
        return dp[n][sum];
     }
int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (subsetsum_DP(set, n, sum) == true)
        cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}
