class Solution {
public:
    string robotWithString(string s) {
       vector<int>last(26,-1);
        int n = s.length();
        for(int i = 0; i< n; ++i){
            last[s[i]-'a'] = i;
        }
        stack<char>st;
        string ans= "";
        // bool flag = 0;
        for(int i = 0; i< n ;++i){
            st.push(s[i]);
            while(!st.empty()){
               bool flag = 0;
                for(int ch = 0;ch<st.top()-'a' ;++ch){
                    if(last[ch]>i){
                        flag=1;
                        break;
                    }
                    
                }
                if(flag){
                    
                    break ;
                }
                else {
                    ans.push_back(st.top());
                    st.pop();
                }
                
            }
                     
           
            
            
            
            
        }
        while(!st.empty()) {ans.push_back(st.top()); st.pop();}
         return ans ;
        
    }
};
