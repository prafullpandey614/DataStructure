class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0 ,ans=0; 
        int j = nums.size()/2;
        int n = nums.size();
        while(i<n/2 && j<n){
            if(nums[i]*2<=nums[j]){
                ans+=2;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return ans ;
    }
};
