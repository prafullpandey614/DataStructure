class Solution {
private:
 bool isSafe(int i,int j,vector<string>&b,int n){
     int r = i ;
     int c = j ;
     while(i>=0 and j>=0){
         if(b[i][j]=='Q') return false;
         i--;
         j--;
     }
     i = r;
     j = c; 
      while(i<n and j>=0){
         if(b[i][j]=='Q') return false;
         i++;
         j--;
     }
     i = r;
     j = c;
     while(j>=0){
         if(b[i][j]=='Q') return 0;
         j--;
     }
     return 1;

 }
public:
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){

        if(col==n) {
            ans.push_back(board);
        }

        for(int i = 0 ; i< n ; ++i){
            if(isSafe(i,col,board,n)){
                board[i][col] = 'Q';
                solve(col+1,board,ans,n);
                board[i][col] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i = 0 ; i < n ; ++i) board[i]= s;
        solve(0,board,ans,n);
        return ans;
    }
};
