class Solution {
public:
    vector<string>ans;
    int conv(string &ds){
        if(ds=="" || ds.length()>3) return -1;
        long long count = 0 ;
        for(int i= 0 ;i <ds.size(); ++i){
            count = count*10+ int(ds[i]-'0');
            if(count>255) return -1 ;
        }
        // cout<<count<<" ";
        return count ;
    }
    bool isValidIP(string &s){
        string curr= "";
        int count=  0  ;
        for(int i = 0; i<s.size(); ++i){
            
            if(s[i]=='.'){
                count++;
                int k = conv(curr);
                if(curr.size()>1){
                    if(curr[0]=='0') return 0;
                }
                if(k<0 or k>255){
                    return 0;
                }
                curr = "";
                
            }
            else{
                curr.push_back(s[i]);
            }
            
        }
        int k = conv(curr);
        
        if(curr.size()>1)
        {
        if(curr[0]=='0') 
            return 0;
        }
        if(k<0 or k>255){
                    return 0;
        }
        return count==3;
    }
    void solve(int ind,string s, string curr,int dot){
        if(ind==s.size()) {
            // cout<<curr<<endl;
            if(isValidIP(curr)){
                ans.push_back(curr);
            }
            return ;
        }
        if(curr.back()=='.' or dot==0){
            curr+=s[ind];
            solve(ind+1,s,curr,dot);
            return ;
        }
        else{
            curr.push_back('.');
            curr.push_back(s[ind]);
            solve(ind+1,s,curr,dot-1);
            curr.pop_back();
            curr.pop_back();
            curr.push_back(s[ind]);
            solve(ind+1,s,curr,dot);            
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        solve(0,s,"",3);
        return ans ;
    }
};
