class Solution {
public:
    bool rec(int ind,vector<int>&nums){
        if(ind==nums.size()-1){
            return 1;
        }
        if(ind>=nums.size()) return 0;
        bool ans = 0;
        while(nums[ind]>0){
            ans = (ans | rec(ind+nums[ind],nums));
            if(ans) return 1;
            nums[ind]--;
        }
        return ans;
        
    }
    bool canJump(vector<int>& nums) {
        return rec(0,nums);
    }
};
