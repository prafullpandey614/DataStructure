class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int l = 0 , r = 0 ; 
        int mf = 0 , mi = 0 ;
        int st = 0 ;
        int ans =0 ;
        while(r<nums.size()){
            mp[nums[r]]++;
            if(mf<mp[nums[r]]){
                mi = r ;
                mf = mp[nums[r]];
            } 
            // if(mf>k){
                while(st <=r and mf>k){
                
                mp[nums[st]]--;
                if(mp[nums[st]]==0){
                    mp.erase(nums[st]);
                }
               
                st++;
                     if(nums[st-1]==nums[r]) {
                            mf--;
                    break ;
                  }
                }
            // }
            ans = max(ans,r-st+1);
            r++;
            
        }

    return ans;
    }
};
