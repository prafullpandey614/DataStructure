//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool helper(int i, int j, int k, int m, int n, vector<vector<char>>& board, string word ){
    if(k==word.size()) return true;
    if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[k]) return false;
    
    int row[]={-1, 0, 1, 0};
    int col[]={0, 1, 0, -1};
    char temp;
    temp=board[i][j];
    board[i][j]='#';
    for(int x=0; x<4; ++x){
    
        if(helper(i+row[x], j+col[x], k+1, m, n, board, word)) return true;
    }
    board[i][j]=temp;
    return false;
}
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int m=board.size();
        int n=board[0].size();
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j]==word[0]){
                    if(helper(i,j, 0, m,n, board, word)) return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
