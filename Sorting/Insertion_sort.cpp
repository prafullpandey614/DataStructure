class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            int minInd = i ;
            for(int j = i +1 ; j<n ; ++j){
                if(nums[minInd]>nums[j]){
                    minInd = j;
                }
            }
            cout<<minInd<<" ";
            swap(nums[i],nums[minInd]);
        }
        cout<<endl;
        return nums;
    }
};
