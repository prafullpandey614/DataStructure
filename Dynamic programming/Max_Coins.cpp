//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
  static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[0] < v2[0];
    }
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> dp(ranges.size(), vector<int>(3, -1));
        return solve(ranges, 0, 2, dp);
    }
    
    int solve(vector<vector<int>> &v, int i, int rem, vector<vector<int>> &dp){
        // rem = number of intervals need to be choosen (remaining)
        if(rem == 0 || i == v.size())
            return 0;
        
        if(dp[i][rem] != -1)
            return dp[i][rem];
        
        int notTake = solve(v, i+1, rem, dp);
        
        int take = v[i][2];
        
        int low = i+1, high = v.size()-1;
        int idx = v.size(); //incase, every interval is overlapping
        while(low <= high){
            int mid = (low+high)/2;
            if(v[mid][0] >= v[i][1]){
                idx = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        take += solve(v, idx, rem-1, dp); //note that we passed idx and not i+1
        return dp[i][rem] = max(take, notTake);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
