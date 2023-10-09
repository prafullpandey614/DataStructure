class Solution {
public:
    int dp[501][501] ;
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int skip_1 = solve(i-1,j,nums1,nums2);
        int skip_2 = solve(i,j-1,nums1,nums2);
        int take_both = solve(i-1,j-1,nums1,nums2) + nums1[i]*nums2[j] ;
        int skip_both = solve(i-1,j-1,nums1,nums2);

        return dp[i][j] = max({skip_1,skip_2,take_both,skip_both});

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        int ans =  solve(nums1.size()-1,nums2.size()-1,nums1,nums2);
         if(ans==0){
            int a = *max_element(nums1.begin(), nums1.end());
            int b = *min_element(nums1.begin(), nums1.end());
           
            int c = *max_element(nums2.begin(), nums2.end());
            int d = *min_element(nums2.begin(), nums2.end());
           
           return max(a*d, b*c);
        }
        return ans;
    }
};


