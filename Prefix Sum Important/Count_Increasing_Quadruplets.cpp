class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n =  nums.size() ;
        vector<vector<int>>left(n+1,vector<int>(n+1,0));
        vector<vector<int>>right(n+1,vector<int>(n+1,0));
        
        for(int i = 0 ; i < nums.size() ; ++i){
            for(int no = 1 ; no<=n ; ++no){
                if(nums[i]<no){
                    left[i][no]++;
                }
                if(i!=0){
                    left[i][no]+=left[i-1][no];
                }
            }
        }
        
        for(int i = nums.size()-1; i>=0; --i){
            for(int no = 1 ; no<=n ; ++no){
                if(nums[i]>no){
                    right[i][no]++;
                }
                if(i!=nums.size()-1){
                   right[i][no]+=right[i+1][no];
                }
            }
        }
        long long ans = 0 ;
        long long left_count = 0 ; 
        long long right_count = 0 ; 
        for(int j =1 ;j < nums.size()-2 ; ++j){
            for(int k = nums.size()-2 ; k >j ; --k){
                if(nums[k]<nums[j]){
                     left_count = left[j][nums[k]];
                     right_count = right[k][nums[j]] ;
                    ans+=left_count*right_count; 
                }
            }
        }
        return ans ;
    }
};
