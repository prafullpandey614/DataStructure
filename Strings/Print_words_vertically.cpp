class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>ans,arr;
        int j = 0;
         stringstream ss(s);
      string word;
        int sz = 0;
      while (ss >> word) {
         if(sz<word.size()){
             sz = word.size();
         }
        arr.push_back(word);
        }
        int c = 0;
   // for(auto words:arr)  sz = max(sz,words.size());
       int idx = 0;
        string curr= "";
        for(int i = 0 ; i < sz ;++i){
            for(auto x:arr){
                if(x.size()>idx){
                    curr.push_back(x[idx]);
                }
                else{
                    curr.push_back(' ');
                }
                
               
            }
            idx++;
            c = curr.size()-1;
             while(c>=0){
                 if(curr[c]==' ') {curr.pop_back();
                                  c--;
                                  }
                 else break;
              
             }
            ans.push_back(curr);
             curr = "";
        }
        
        return ans;
        
    }
};
