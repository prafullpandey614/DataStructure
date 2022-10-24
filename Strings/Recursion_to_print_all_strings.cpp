class Solution {
    // int ans ;
public:
    
    void dfs(vector<string>& arr, string s, int idx ,vector<int>&ans){
        if(idx==arr.size()){
            if(uniqueCount(s)>ans[0]){
                ans[0] = s.length();
                return ;
            }
            return ;
        }
        
        
        dfs(arr,s,idx+1,ans);
        dfs(arr,s+arr[idx],idx+1,ans);
        
    }
    int uniqueCount(string s){
        vector<int>v(26,0);
        for(char c:s){
            v[c-'a']++;
            if(v[c-'a']>1) return -1;
           
        }
        
        return s.length();
    }
    int maxLength(vector<string>& arr) {
        // ans=0;
        // int ans[0];
        vector<int>ans(1,-90);
        dfs(arr,"",0,ans);
        return ans[0];
    }
};
