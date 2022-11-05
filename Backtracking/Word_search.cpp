class Solution {
public:
    
    bool dfs(int i,int j,int idx,vector<vector<char>>& board,string word){
        if(idx==word.size()){
            return 1;
        }
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || board[i][j]!=word[idx]){
            return  0;
        }
        
        board[i][j]='#';
        bool b1 = dfs(i+1,j,idx+1,board,word);
        bool b2 = dfs(i-1,j,idx+1,board,word);
        bool b3 = dfs(i,j+1,idx+1,board,word);
        bool b4 = dfs(i,j-1,idx+1,board,word);
        
        board[i][j]=word[idx];
        return b1||b2||b3||b4 ;

    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0 ; i< board.size() ; ++i){
            for(int j = 0; j  < board[0].size() ; ++j){
                if(dfs(i,j,0,board,word)) return 1;
            }
        }
        return 0 ;
    }
};
