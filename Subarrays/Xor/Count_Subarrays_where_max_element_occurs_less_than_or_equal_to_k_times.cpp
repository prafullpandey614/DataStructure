class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp ;
        int n = nums.size();
        // int f[n]= {0};
        vector<int>f(n,0);
        int mx = *max_element(nums.begin(),nums.end());
        unordered_map<int,vector<int>>dp;
        int freq = 0 ;
        for(int i =0 ; i< nums.size() ; ++i){
            if(nums[i]==mx){
                freq++;
            }
            f[i] = freq ;
            
            dp[freq].push_back(i);
        }   
        long long ans = 0; 
        for(int i = 0 ;i < nums.size(); ++i){
            if(f[i]<k) continue ;
            // cout<<"Jhinga --"<<f[i]<<endl;
            ans+=(dp[f[i]-k+1][0]+1);
        }
        return ans ;
    }
};
