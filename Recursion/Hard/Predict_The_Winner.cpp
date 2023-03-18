class Solution {
    private:
    int pscore= 0 ;
    bool flag =  0; 
    int dscore = 0 ;
public:
    int score(int st,int end,vector<int>&nums){
        if(st>end) return 0 ;
        if(st==end) return nums[st];
        return max(nums[st]+min(score(st+2,end,nums),score(st+1,end-1,nums)),nums[end]+min(score(st+1,end-1,nums),score(st,end-2,nums)));
    }
    bool PredictTheWinner(vector<int>& nums) {
       
        int sc = score(0,nums.size()-1,nums);
        cout<<sc<<" ";
        int dc = accumulate(nums.begin(),nums.end(),0)-sc;
        return dc<=sc;
        // return 1;
        
    }
};
