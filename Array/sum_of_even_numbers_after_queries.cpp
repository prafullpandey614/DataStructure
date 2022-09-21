class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int>ans;
        vector<bool>v(nums.size());
          int cnt = 0;
        int i = 0;
         
        for(int i=0;i<nums.size() ;++i){
            if(((nums[i])&1)==0) {
                cnt+=nums[i];
                v[i]  = 1;
            }
        }
      
        for(int i = 0 ; i < q.size() ;++i){
            
            int temp = nums[q[i][1]];
            if(temp%2==0)
            cnt-=temp;
            nums[q[i][1]]+=q[i][0];
            if(nums[q[i][1]]%2==0){
                cnt+=nums[q[i][1]];
            }
            ans.push_back(cnt);
        }
         
        return ans;
    }
    
};
