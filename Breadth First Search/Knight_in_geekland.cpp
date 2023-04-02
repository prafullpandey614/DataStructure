//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int x,int y,vector<vector<int>> &arr){
        int n = arr.size(), m = arr[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        q.push({x,y});
        vector<int>coins ;
        while(!q.empty()){
            int sz = q.size();
            int sum = 0 ;
            for(int i = 0 ; i <sz; ++i){
                auto f = q.front();
                q.pop();
                int a = f.first ;
                int b = f.second ;
                if(a<0 || b<0 || a>=n || b>=m) continue ;
                if(!vis[a][b]){
                sum+=arr[a][b];
                vis[a][b] = 1;
                q.push({a+2,b+1});
                q.push({a+2,b-1});
                q.push({a-2,b+1});
                q.push({a-2,b-1});
                q.push({a+1,b+2});
                q.push({a+1,b-2});
                q.push({a-1,b+2});
                q.push({a-1,b-2});
                }
            }
            coins.push_back(sum);
        }
        
        // Coins array is prepared
        int ans = - 1,sum=INT_MIN;
        for(int i =coins.size()-1; i>=0 ; --i){
            if(i+coins[i]<coins.size())
            coins[i] = coins[i]+coins[i+coins[i]];
            if(coins[i]>=sum){
                
                 ans = i ;
                sum = coins[i] ;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends
