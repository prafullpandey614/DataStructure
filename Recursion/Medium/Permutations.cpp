class Solution {
public:
      vector<vector<int>>ans;
    vector<bool>flag;
    vector<vector<int>> permute(vector<int>& nums) {
        
        flag.resize(nums.size()+1,0);
        recursion(nums,{});
        return ans;
    }
    
    void recursion(vector<int>& nums,vector<int>curr){
        if(curr.size()>=nums.size()){
            ans.push_back(curr);
            return ;
        }
        for(int i=0;i<nums.size(); ++i){
            if(!flag[i]){
                flag[i] = 1;
                curr.push_back(nums[i]);
                recursion(nums,curr);
                curr.pop_back();
                flag[i]=false;
            }
        }
    }
    
};
