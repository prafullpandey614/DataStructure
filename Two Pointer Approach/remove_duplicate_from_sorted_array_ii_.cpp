class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = INT_MIN;
        int count = 0;
        int j = 0;
        for(int i = 0 ;i < nums.size();++i){
            if(nums[i]!=prev){
            nums[j++] = nums[i];
                prev = nums[i];
                count=1;
            }
            else{
                if(count<2)
                nums[j++] = nums[i];
                count ++;
            }
        }
        return  j ;
    }
};
