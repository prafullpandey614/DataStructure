class Solution {
public:
    vector<string>ans;
    void toLowerCase(char &c){
        c= c|32 ;
        return ;
    }
    void toUpperCase(char &c){
        int x = 32;
        c= c & ~x;
        return ;
    }
    bool isLow(char c){
        if (c>96 && c<123){
            return 1;
        }
        return 0;
    }
    bool isUpp(char c){
        if (c>64 && c<91){
            return 1;
        }
        return 0;
    }
    bool isAnything(char c){
        if ((c>=91 && c<97) || (c<=64)|| c>122){
            return 1;
        }
        return 0;
    }
    void rec(int ind,string s,string curr){
        if(curr.size()==s.size()){
            ans.push_back(curr);
            return ;
        }
        if(isAnything(s[ind])){
            curr.push_back(s[ind]);
            rec(ind+1,s,curr);
            return ;
        }
        curr.push_back(s[ind]);
        rec(ind+1,s,curr);
        curr.pop_back();
        if(isUpp(s[ind])){
            toLowerCase(s[ind]);
            curr.push_back(s[ind]);
            rec(ind+1,s,curr);
            return ;
        }
        else{
             toUpperCase(s[ind]);
            curr.push_back(s[ind]);
            rec(ind+1,s,curr);
            return ;
        }
    }
    vector<string> letterCasePermutation(string s) {
        rec(0,s,"");
        return ans;
    }
};
