#9. Is palindrome
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.


Solution:

class Solution {
public:
    bool isPalindrome(int x) {
        int s= 0 ;
        if(x < 0){ return false;}
        
        string num = std::to_string(x);
        int e = num.size()-1;
        while( s <= e){
            if(num[s] != num[e]) return false;
            s+=1;
            e-=1;
        }
        return true;
            
    }
};