class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        int count = 0 ;
        vector<bool>visited(S.size(),0);
        for(int i = 0 ; i  < S.size() ; ++i){
            if(S[i]==W[0] && !visited[i]){
                int j = i+1; 
                int k = 1;
                while(j<S.length()  && k< W.length() ){
                    if(S[j]==W[k] && !visited[j]){
                        k++;
                        visited[j] =1;
                    }
                    
                    
                    j++;
                    
                }
                if(k==W.length()){
                   count++;
                }
            }
        }
        return count ;
        
    }
};
