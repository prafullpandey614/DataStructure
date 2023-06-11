class Solution {
public:
    string smallestString(string s) {
        string ans = "";
        int i = 0;
        for( i = 0; i < s.size(); ++i){
            if(s[i]!='a'){
                ans.push_back(char(s[i]-1));
            }
            else break;
        }
        if(i==0){
            while(i<s.size() and s[i++]=='a')
            ans.push_back('a');
            
            if(ans.size()==s.size()){ ans[i-1]='z';
                           return ans;
                }
            
            
            for( i=i-1 ; i < s.size(); ++i){
            if(s[i]!='a'){
                ans.push_back(char(s[i]-1));
                }
            else break;
            }
        }
        cout<<i<<endl;
       ans += s.substr(i);
        
        return ans ;
    }
};
