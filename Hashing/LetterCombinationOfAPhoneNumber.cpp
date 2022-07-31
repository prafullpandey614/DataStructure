class Solution {
public:
    map<int,string>mp;
    
    void rec(string digits , vector<string>&ans , int ind , string temp){
        
        if(ind>=digits.size()){
            ans.push_back(temp);
            temp = "";
            return ;
        }
        int k = digits[ind]-'0';
        string cur = mp[k];
        for(int i= 0;i< cur.size();++i){
            temp+=cur[i];
            rec(digits,ans,ind+1,temp);
            temp.pop_back();
        }
       
        
        return  ;
        
    }
    vector<string> letterCombinations(string digits) {
        mp[2]  = "abc" ;
        mp[3]  = "def" ;
        mp[4]  = "ghi";
        mp[5] = "jkl" ;
        mp[6] = "mno" ;
        mp[7] = "pqrs" ;
        mp[8] = "tuv" ;
        mp[9] = "wxyz" ;
        // for(auto x:mp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
         vector<string>ans ;
        if(digits=="") {return ans;}
        string temp = "";
        rec(digits,ans,0,temp);
        return ans ;
    }
};
