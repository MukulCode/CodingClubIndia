class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cur = 0 , maxx = 0 ;
        int mlen = 0;
        int n = nums.size();
        for(int x:nums){
            maxx = max(maxx, x);
        }
        for(int i = 0 ;i <n; i++){
            if(nums[i] == maxx)
                cur+=1;
            else cur = 0;
            mlen = max(mlen, cur);
        }
        return mlen;
    }
};