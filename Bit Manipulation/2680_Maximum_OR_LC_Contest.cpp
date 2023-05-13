class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long pref[nums.size()+1] ;long long suff[nums.size()+2];
       int i=1;
        pref[0]=0 ;
        suff[nums.size()]= 0;
        for(int x:nums){
            pref[i] = pref[i-1]|x;
            i++;
        }
    i = nums.size();
        // suff[i] = nums[i-1];
        for(int j = nums.size()-1; j>=0 ; --j){
            suff[j] = suff[j+1]|nums[j];
        }
         long long ans = 0 ;
        for(int i = 0 ;i<nums.size(); ++i){
            ans = max(ans,(((nums[i]*1LL*(1<<k))| pref[i])|suff[i+1]));
        }
        return ans ;
    }
};
