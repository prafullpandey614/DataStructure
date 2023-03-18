class Solution {
public:
    string solve(int& ind,string s){
      
        string n ;
        string str ="";
        while(ind<s.size()){
            if(s[ind]=='['){
                int m = stoi(n);
                ind+=1;
                string result = solve(ind,s);
                
                while(m--) str+=result ;
                n="";
                
            }
            else if(isdigit(s[ind])){
                n+=s[ind];

            }
            else if(s[ind]==']'){
                return str ;
            }
            else{
                str.push_back(s[ind]);
            }
            ind++;
        }
        return str ;
    }
    string decodeString(string s) {
        int ind = 0 ;
        return solve(ind,s);
        
    }
};
