/*Problem Link: https://leetcode.com/problems/edit-distance/description/



Problem Description:
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character



Approach:

We need to convert word1 to word2 using any of the three options. We see here that we have a choice of performing either of the transformations in case we do not have a 
match. This gives an idea of trying out all possible solutions and leads us to apply recursive approach for finding minimum operations.

We start with the very first character of both the strings and have two cases to explore:

Case 1: If there is a match we do not perform any operation and make a call for the next character match check
Case 2: If there is not a match then we can perform either of the 3 operations and go on to find the minimum out of all 3. We also add a count to our final answer as we 
perform any of the 3 operations

// i is pointer for word1 and j is pointer for word2

In case of a character INSERT operation the pointer to word1 does not change as we add a character but for word2 changes while making a call as we assume that after inserting a character at word1 there is a match so we need to make matches from next character of word2 (i,j+1)

In case of a character DELETE the pointer to word1 changes as we remove a character and but does not change for word2 as we want to make a match from next character of word1 with the current character of word2 changes while making a call (i+1,j)

In case of a character REPLACE the pointer to both word1 and word2 changes while making a call (i+1,j+1) because by replacing we have made a match

In case of a match we do not add to move rather make a simple call to (i+1,j+1)


Time Complexity:  O(n*m) 
Space Complexity: O(n*m) 




Implementation in C++:

**/


class Solution {
public:
    
    int dp[505][505];
    int Distance(string word1 , string word2 , int i , int j){
        
       if(i == word1.length()){
           return dp[i][j] = word2.length() - j;
       }
        
       if(j == word2.length()){
           return dp[i][j] = word1.length() - i;
       }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
       if(word1[i]==word2[j]){
           return dp[i][j] = Distance(word1,word2,i+1,j+1);
        }
        
        return dp[i][j] = 1+min(Distance(word1,word2,i+1,j+1),
               min(Distance(word1,word2,i+1,j),Distance(word1,word2,i,j+1)));
        
    }
    
    
    int minDistance(string word1, string word2) {
        
        
        memset(dp,-1,sizeof(dp));
        return Distance(word1,word2,0,0);
    }
};