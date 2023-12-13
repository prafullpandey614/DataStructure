class Solution {
public:
    int maxProduct(vector<int>& nums) {
      sort(nums.begin(),nums.end(),greater<int>());
      return (--nums[0])*(--nums[1]);   
    }
};
