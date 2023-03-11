class Solution {
public:
    #define pb push_back
    vector<int> diffWaysToCompute(string exp) {
        char curr ; 
        vector<int>ans; 
        for(int i = 0; i < exp.size(); ++i){
          curr = exp[i];
          if(curr=='+' || curr=='*' || curr=='-'){
              //we can calculate all the possible result of left part and right part individually
              vector<int>left = diffWaysToCompute(exp.substr(0,i)); //left substr
              vector<int>right = diffWaysToCompute(exp.substr(i+1)); //right substr
              for(int x:left){
                  for(int r:right){
                     if(curr=='+'){
                         ans.pb(x+r);
                     }
                     else if(curr=='*'){
                         ans.pb(x*r);
                     }
                     else{
                         ans.pb(x-r);
                     }
                  }
              }
          }

        }
        if(ans.size()==0){
            ans.pb(atoi(exp.c_str()));
        }
        return ans ;

    }
};
