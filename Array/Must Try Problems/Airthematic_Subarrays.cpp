class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>kums;
        vector<int>p = nums ;
        for(int i = 0 ; i < l.size(); ++i){
            nums = p ;
            sort(nums.begin()+l[i],nums.begin()+r[i]+1);
            
            int diff = nums[l[i]+1]-nums[l[i]] ;
            bool flag = 1 ;
            
            for(int j = l[i]+1 ; j <=r[i]; ++j){
                if(nums[j]-nums[j-1]!=diff){
                    flag = 0 ;
                    break ;
                }
                
            }
          
            kums.push_back(flag);
        }
        
        return kums;
    }
};
