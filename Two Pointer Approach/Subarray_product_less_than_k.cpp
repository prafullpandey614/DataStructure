class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1,ans= 0 ;
        int i = 0; int j =0 ; 
        while(j<nums.size()){
            prod = prod*nums[j];
            // if product is greater than K 
            if(prod>=k){
                while(i<=j and prod>=k){
                    //keep moving i and remove it from product
                    prod = prod/nums[i++];
                    // if anywhere product >=k is failed this loop will break
                }
            }
            ans = ans+j-i+1 ; // this logic is to find number of subarrays
            j++;

        }
        return ans ;
    }
};
