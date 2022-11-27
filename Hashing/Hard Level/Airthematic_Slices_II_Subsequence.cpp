class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        map<long long int,long long int>mp[nums.size()] ;
        long long int ans = 0;
        for(int i = 0 ; i <  nums.size();++i){
            for(int  j = 0 ; j < i;++j){
                long long int diff = (long)(nums[j])-nums[i];
                if(diff<INT_MIN || diff>INT_MAX) continue ;
                long long int k = mp[i][diff];
                long long int f = mp[j][diff];
                ans+=f;
                long long freq = k+f+1;
                mp[i][diff] = freq;
            }
        }
        return ans ;
        
    }
};
