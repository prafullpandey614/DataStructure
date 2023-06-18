class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 1e9 +10;
        for(int i = 0 ;i < nums.size()-1; i++){
            if(nums[i+1]-nums[i]<ans){
                ans = nums[i+1]-nums[i];
            }
        }
        return ans;
    }
};
