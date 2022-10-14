35. Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


Solution:

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), s = 0 , e = nums.size(), mid;
        if(target < nums[0]) return 0;
        if(target > nums[n-1] ) return n;
        int index = -1;
        while( s <=e ){
            mid = (s+e)/2;
            if(nums[mid] >= target){
                index = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return index;
    }
};