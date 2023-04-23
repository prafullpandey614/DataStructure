class Solution {
public:
    int solve(int ind,string &s,int k,int curr){
        if(ind==s.size()) {
            if(curr>0 and curr<=k) return 1;
            return 0;
        }
        int ans = 0 ;
        if(curr<=0 or curr>k) return 0;
        curr = curr*10+(s[ind]-'0');
        if(curr>0 and curr<=k){
        ans+=solve(ind+1,s,k,curr);
            //  curr-=(s[ind]-'0');
            //  curr/=10;
        
        ans+=solve(ind+1,s,k,s[ind]-'0');
        return ans ;
        }
        else{
            return 0;
        }
      
       
    }
    int numberOfArrays(string s, int k) {
        // string curr= "";
        return solve(0,s,k,1);
    }
};
