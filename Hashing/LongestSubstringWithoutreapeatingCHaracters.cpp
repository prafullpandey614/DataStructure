class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxans = 0;
        int leftInd  = 0 ;
        unordered_set<char>st ;
        for(int i = 0; i<s.size();++i){
            if(st.find(s[i])!=st.end()){
                while(leftInd < i && st.find(s[i])!=st.end()){ st.erase(s[leftInd]); leftInd++;}
            }
            st.insert(s[i]);
            maxans = max(maxans , i-leftInd+1) ;
            //this line is confusion creation but its pretty easy to understand that ength of the substring will be i-l+1
                
        }
        return maxans; 
    }  
    
};
