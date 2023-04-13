class Solution {
public:
    bool validateStackSequences(vector<int>& p, vector<int>& pp) {
        stack<int>st;
        int i = 0 ;
        int j = 0 ;
        for(i ; i < p.size(); ++i){
            st.push(p[i]);
            if(p[i]==pp[j]){
               
                while(st.size() and pp[j]==st.top()){
                    st.pop();
                    j++;
                }
            }
        }
        return j>=pp.size();
    }
};
