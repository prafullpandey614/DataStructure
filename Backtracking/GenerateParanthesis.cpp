class Solution {
public:
    vector<string>v;
    void generate(string &s,int l,int r){
        if(l==0 && r==0){
            v.push_back(s);
            return;
            
        }
        if(l>0){
            s.push_back('(');
            generate(s,l-1,r);
            s.pop_back();
        }
        if(r>0){
            if(l<r){s.push_back(')');
                generate(s,l,r-1);
                    s.pop_back();
            }
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        generate(s,n,n);
        return v;
    }
};
