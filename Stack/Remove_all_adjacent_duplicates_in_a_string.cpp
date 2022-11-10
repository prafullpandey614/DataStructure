 string removeDuplicates(string s) {
        stack<char>st;
        for(char c:s){
            if(st.empty()){
                st.push(c);
            }
            else{
                if(st.top()==c){
                    st.pop();
                }
                else st.push(c);
            }
        }
       
        s= "";
        while(!st.empty()){
           s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
        
    }
