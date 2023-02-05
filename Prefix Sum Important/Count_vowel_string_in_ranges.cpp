class Solution {
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& queries) {
        vector<int> v(w.size(),0);
        for(int i=0;i<w.size();i++)
        {
            string s=w[i];
            if((s[0] == 'a' or  s[0] == 'e' or s[0] == 'i'  or s[0] == 'o'  or s[0] == 'u') && (s[s.size()-1]== 'a' or  s[s.size()-1] == 'e'    or s[s.size()-1] == 'i' or s[s.size()-1] == 'o' or s[s.size()-1] == 'u'))
                v[i]=1;
        }
        vector<int> ans;
        vector<int> pre(w.size(),0);
        pre[0]=v[0];
        for(int i=1;i<w.size();i++)
        {
            pre[i]=v[i]+pre[i-1];
        }
        for(auto i:queries)
        {
            if(i[0]==0)
                ans.push_back(pre[i[1]]);
            else 
            ans.push_back(pre[i[1]]-pre[i[0]-1]);
        }
        return ans;
    }
};
