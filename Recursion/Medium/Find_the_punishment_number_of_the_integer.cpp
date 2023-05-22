class Solution {
public:
    bool solve(string sq,int curr,int n,int ind){
        if(ind==sq.size()){ 
            if(n==46) cout<<n<<" "<<curr<<endl;
            return curr==n;
        
        }
        bool ans = 0 ;
        int dis = 0;
        for(int i = ind ; i < sq.size(); ++i){
            dis = dis*10+sq[i]-'0';
            ans |= solve(sq,curr+dis,n,i+1);
        }
        // if(ans) return 1;
         
        return ans ;
        
    }
    int fun(int b,int n){
        return 0;
    }
    int punishmentNumber(int n) {
        int result = 0 ;
        for(int i = 1;  i<=n ; ++i){
            int sq = i*i;
            string str = to_string(sq);
            bool ans = solve(str,0,i,0);
            
            if(ans){
                result += sq ;
            }
        }
        return result ;
    }
};
