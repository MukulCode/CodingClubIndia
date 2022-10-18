class Solution {
    public int[] twoSum(int[] nums, int target) {
        int arr[] = new int[2];
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; ++i) {
            mp.put(nums[i], i);
        }
        
        for(int j = 0; j < nums.length; ++j) {
            int comp = target - nums[j];
            if(mp.containsKey(comp)) {
                int val = mp.get(comp);
                if(val == j) {
                    continue;
                }
                else {
                    arr[0] = j;
                    arr[1] = val;
                    break;
                }
            }
         }
        return arr; 
    }
}
