class Solution {
    public long maximumTripletValue(int[] nums) {
         int n = nums.length;
    
    int[] mini = new int[n];
    int[] maxi = new int[n];
    
    int curr = 0;
    for (int i = n - 1; i >= 0; i--) {
        curr = Math.max(curr, nums[i]);
        maxi[i] = curr;
    }
    
    curr = 0;
    for (int i = 0; i < n; i++) {
        curr = Math.max(curr, nums[i]);
        mini[i] = curr;
    }
    
    long result = 0;
    for (int i = 1; i < n - 1; i++) {
        result = Math.max(result, (long)(mini[i - 1] - nums[i]) * maxi[i + 1]);
    }
    
    return result;
    }
}
