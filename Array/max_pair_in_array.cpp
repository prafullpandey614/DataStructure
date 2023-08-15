class Solution {
public:
    int maxd(int d){
        int k = -1 ;
        while(d){
            k = max(k,d%10);
            d/=10;
        }
        return k ; 
    }
    int maxSum(vector<int>& nums) {
        vector<int>md ;
        for(int x:nums){
            md.push_back(maxd(x));
        }
        int ans = -1; 
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i+1 ; j< nums.size(); ++j){
                if(md[i]==md[j]){
                    ans = max(ans,nums[i]+nums[j]);
                }
            }
        }
        return ans ;
    }
};
