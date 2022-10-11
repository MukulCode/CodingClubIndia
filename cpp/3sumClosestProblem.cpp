#include <bits/stdc++.h>
using namespace std;

/*
Question:-
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    int isNeg = 1;
    int low, high, i, t, n = nums.size();
    for (i = 0; i < n - 2; i++)
    {
        if (i == 0 || nums[i] > nums[i - 1])
        {
            low = i + 1, high = n - 1, t = target - nums[i];
            while (low < high)
            {
                int temp = target - (nums[low] + nums[high] + nums[i]);
                if (nums[low] + nums[high] == t)
                {
                    return target;
                }
                else if (nums[low] + nums[high] > t)
                    high--;
                else
                    low++;
                if (temp < 0 && ans > (-1 * temp))
                    ans = min(ans, -1 * temp), isNeg = 1;
                else if (temp > 0 && ans > temp)
                    ans = min(ans, temp), isNeg = -1;
            }
        }
    }
    return target + ans * isNeg;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
     cin>>nums[i];
    cout<<threeSumClosest(nums,target);
}