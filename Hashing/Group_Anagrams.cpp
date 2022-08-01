class Solution {
public:
   //This Question Is Solved By Me Without taking any Help 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
       
        vector<vector<int>>v;
        for(string s:strs){
            string t = s ;
            sort(s.begin(),s.end());
            mp[s].push_back(t);
        }
        for(auto x:mp){
            
            ans.push_back(x.second);
        }
        return ans ;
        
        
    }
};
