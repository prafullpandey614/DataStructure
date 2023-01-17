class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0;
        
        int flip = 0 ; 
        int cnt = 0 ;
        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i]=='1'){
                cnt++;
                
            }
            else {
                flip++;
            }
            flip = min(flip,cnt);
        }
        return flip;
    }
};
