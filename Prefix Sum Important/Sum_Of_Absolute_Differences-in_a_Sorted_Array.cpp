class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int pf[nums.size()+1];
        pf[0]=0;
        for(int i = 1; i <= nums.size() ; ++i){
            pf[i] = pf[i-1]+nums[i-1];
        }
        vector<int>ans(nums.size(),0);
        for(int i = 1; i <= nums.size() ; ++i){
            int lft_ind = i-2 ;
            int rht_ind = i ;
            if(lft_ind>=0)
            ans[i-1] = (i-1)*nums[i-1] - pf[lft_ind+1]+(pf[nums.size()]-pf[rht_ind])-(nums.size()-rht_ind)*nums[i-1] ;
            else{
                ans[i-1] = (pf[nums.size()]-pf[rht_ind])-(nums.size()-rht_ind)*nums[i-1] ;
            }
        }
        return ans ;
    }
};
