
//This Question is perfect for getting started with unions 
//approach : We are storing parent of each operands in this format
//    ("a==b") -> parent[a] = a & parent[b] = a 
//    and after that we are checking that for each string if the oprands are not equal 
   
//      ("a != b") or ("c!=b")
    
//    than there parents must differ if not the return Zero 
// First try implementing the above approach then if not able to write the code then take help fro here

class Solution {
public:
    int fetchParent(int a,vector<int>&p){
        if(p[a]==a){
            return a;
        }
        else return fetchParent(p[a],p);
    }
    bool equationsPossible(vector<string>& equations) {
      int n = equations.size();
        vector<int>parent(26);
        for(int i = 0; i< 26 ;++i){
            parent[i] = i;
        }
        
        for(auto s:equations){
            char eq = s[1];
         
            if(eq=='='){
               int var1 = fetchParent(s[0]-'a',parent);
               int var2 = fetchParent(s[3]-'a',parent);
                
                 if(var1!=var2){
                parent[var2] = var1;
                }
            }
           
            
        }
        
        for(auto s:equations){
            
            if(s[1]=='!'){
               int var1 = fetchParent(s[0]-'a',parent);
               int var2 = fetchParent(s[3]-'a',parent);
                if(var1==var2) return 0;

            }
            
        }
        return 1;
        
    }
};
