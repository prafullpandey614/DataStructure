class Solution {
public:
    int countHomogenous(string s) {
        // sort(s.begin(),s.end());
        int ans = 1 ;
        int m = 1e9+7 ;
        char p = s[0] ;
        int cnt = 1 ;
        for(int i = 1 ;i < s.size(); ++i){
            if(s[i]!=p){
                cnt = 1 ;
                ans+=cnt ;
                p = s[i];
            }
            else{
                cnt=(cnt+1)%m;
                ans=(ans+cnt)%m;
            }
        }
        return ans ;
    }
};
