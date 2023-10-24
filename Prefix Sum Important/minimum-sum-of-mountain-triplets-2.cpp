class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int>left(nums.size()+1,INT_MAX) ,right(nums.size()+1,INT_MAX);
        for(int i = 1; i <=nums.size() ; ++i){
            left[i] = min(left[i-1],nums[i-1]);
        }
        for(int i = nums.size()-1; i>=0; --i){
            right[i] = min(right[i+1],nums[i]);
        }
        int sum = INT_MAX;
        for(int i = 0 ;i < nums.size(); ++i){
            if(nums[i]!=left[i+1] and nums[i]!=right[i])
            sum = min(sum,nums[i]+left[i+1]+right[i]);
        }
        return sum == INT_MAX ? -1 : sum;
    }
};
