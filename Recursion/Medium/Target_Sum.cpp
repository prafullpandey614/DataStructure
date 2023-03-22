class Solution {
public:
    
    int solve(vector<int>&nums,int ind,int target,int sum){
        if(ind==nums.size()){
            return target==sum;
        }
        return solve(nums,ind+1,target,sum+nums[ind])+solve(nums,ind+1,target,sum-nums[ind]);
    
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,target,0);
    }
};
