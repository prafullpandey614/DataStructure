 int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<float>ans;
        for(int i=0;i<nums.size()/2;++i){
            ans.insert(((float)nums[i]+(float)nums[nums.size()-1-i])/2);
            
        }
        return ans.size();
    }
