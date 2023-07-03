class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = nums.size() ;
        int st = 0 ; 
        int end =st+1 ;
        int mini = nums[st];
        int maxi = nums[st];
        while(end<nums.size()){
            mini = min(mini,nums[end]);
            maxi = max(maxi,nums[end]);
            if(maxi-mini>2){
                int temp_min = nums[end];
                int temp_max = nums[end];
                int ind = end ;
                while(ind>=st){
                    temp_min = min(temp_min,nums[ind]);
                    temp_max = max(temp_max,nums[ind]);
                    if(temp_max-temp_min>2)
                    {
                        st = ind+1 ;
                        break;
                    }
                    ind--;
                }
                mini = temp_min;
                maxi = temp_max;
            }
            
                ans+=end-st;
            
            end++;
        }
        return ans;
    }
};
