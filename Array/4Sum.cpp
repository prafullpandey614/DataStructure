class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result ;
        if(nums.empty()) return result ;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n ;++i){
           long long int target3 = target- nums[i];
            for(int j = i+1; j <n;++j){
              long long  int target2 = target3- nums[j];
                int front = j+1;
                int back  = n-1 ;
                while(front < back){
                  long long  int sum = nums[front]+nums[back] ;
                    if(target2>sum){
                        front++ ;
                    }
                    else if(target2<sum){
                        back-- ;
                    }
                    else{
                        vector<int>result2 ;
                        result2.push_back(nums[i]);
                        result2.push_back(nums[j]);
                        result2.push_back(nums[front]);
                        result2.push_back(nums[back]);
                        result.push_back(result2);
                         while(result2[2]==nums[front] && front<back) front++;
                         while(back>front && result2[3]==nums[back])  back--;
                        
                    }
                   
                }
                while(j+1<n && nums[j]==nums[j+1]) j++ ;
                
            }
            while(i+1<n && nums[i]==nums[i+1]) i++ ;
        }
        return result ;
    }
};
