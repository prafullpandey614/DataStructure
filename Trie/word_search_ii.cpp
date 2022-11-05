class Solution {
    
    int m,n;
    struct Node{
        Node* links[26];
        bool isEnd = 0;
        string endString = "";
       bool isContainsKey(char a){
          return links[a-'a'];
       }
        void put(char c, Node*node){
            
            links[c-'a'] = node ;
        }
        Node* get(char c){
            return links[c-'a'];
        }
        void setEnd(string s){
            endString = s;
            isEnd = 1;
        }
        bool isThisEnd(){
            return isEnd ;
        }
    };
private:Node*root= new Node()  ;
public:
     void insert(string word) {
        Node *node = root ;
        for(int i = 0; i < word.size() ; ++i){
            if(!node->isContainsKey(word[i])){
                node->put(word[i],new Node());
            }
            node =  node->get(word[i]);
        }
        node->setEnd(word);
    }
//     bool search(string word) {
//         Node *node = root ; 
//         for(int i = 0; i <word.size() ;++i){
//             if(!node->isContainsKey(word[i])){
//                 return 0 ;
//             }
//             node = node->links[word[i]-'a'];
//         }
        
//         return  node->isThisEnd();
//     }
    
    
    void dfs(int i,int j,vector<vector<char>>& board,vector<string>&ans ,Node*t){
        if(i>=m || j>= n || i<0 || j<0 || board[i][j]=='*'||t->links[board[i][j] - 'a'] == NULL) return ;
        char c = board[i][j];
        
        t = t->links[c-'a'];
        if(t->endString!=""){
                ans.push_back(t->endString);
                t->endString = "";
             
            }
    
         
            board[i][j] = '*';
            
            dfs(i+1,j,board,ans,t);
            dfs(i-1,j,board,ans,t);
            dfs(i,j+1,board,ans,t);
            dfs(i,j-1,board,ans,t);
            
           board[i][j] = c;
        
        
        
        
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       Node*node  =root ;
        vector<string>ans  ;
        for(string word:words) insert(word);
        m = board.size();
        n = board[0].size();
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0; j < n ; ++j){
                dfs(i,j,board,ans,node);
            }
        }
        set<string>st;
        for(auto c:ans) st.insert(c);
        vector<string>a2 ;
        for(auto c:st) a2.push_back(c);
        return a2 ;
    }
};
