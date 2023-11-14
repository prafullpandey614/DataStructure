class Solution {
public:
    int uniquue(string&s,int i,int j){
         set<char>st;
        for(i ; i <=j ; ++i){
            st.insert(s[i]);
            }
            return st.size();
    }
    int countPalindromicSubsequence(string s) {
        int fi[26] ;
        int li[26] ;
        const int n = s.size() ;
        vector<int>pf(n+1,0);
        set<char>st;
        for(int i = 0; i <26 ; ++i){
            fi[i] = -1 ;
            li[i] = -1;
        }
        for(int i = 0; i <s.size() ; ++i){
            st.insert(s[i]);
            pf[i] = st.size();
            if(fi[s[i]-'a']==-1) {
                fi[s[i]-'a'] = i ;
            }
            li[s[i]-'a'] = i ; 
        }
        int ans = 0 ;
        for(int i =  0 ; i<26 ; ++i){
           
            if(li[i]-fi[i]>=2){
                
                ans += uniquue(s,fi[i]+1,li[i]-1);
              
                }
            
        }

        return ans ; 
        
    }
};
