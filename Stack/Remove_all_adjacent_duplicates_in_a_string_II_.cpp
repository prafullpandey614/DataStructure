class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        
        for(char c:s){
            
            if(st.empty()){
                st.push({c,1});
            }
            else{
               
               if(st.top().first==c){
                    st.top().second++;
                    if(st.top().second>=k){
                    st.pop();
                    }
                }
                else{
                     st.push({c,1});
                }
            }
        }
        s ="";
        while(!st.empty()){
            for(int i=0;i<st.top().second ; ++i)
                  s.push_back(st.top().first);
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
