//Problem link : https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int start = 0 ,end = 1;
        int sum = 0,diff= 0;
        for(int i = 1 ; i < nums.size() ; ++i){
             diff = -nums[start]+nums[end];
            while(i+1<nums.size() && diff==nums[i+1]-nums[i]){
                i++;
                end++;
            }
            int len = end-start+1; //length of subarray
            if(len>=3){
                len-=2  ; //excluding the last two elements
                sum+=(len)*(len+1)/2 ;
            }
            start = end ;
            end++;
        }
        return sum ;
    }
};
