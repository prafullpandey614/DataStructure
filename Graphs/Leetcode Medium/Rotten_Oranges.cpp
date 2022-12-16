class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
         int m = grid[0].size();
        int vis[n][m];
        int countFresh = 0;
        int mx_time  = 0;
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
               else vis[i][j]=0;
                if(grid[i][j]==1) countFresh++;
            }
        }
        int count = 0;
        int r_offsets[4] = {1,0,-1,0};
        int c_offsets[4] = {0,1,0,-1};
         while(q.size()){
                int drow = q.front().first.first ;
                int dcol = q.front().first.second ;
                int Curr_time = q.front().second ;
                q.pop();
                mx_time = max(mx_time,Curr_time);
                for(int i = 0 ; i < 4 ; ++i){
                    int negihbor_row  = drow  + r_offsets[i];
                    int negihbor_col  = dcol  + c_offsets[i];
                    if(negihbor_row>=0 && negihbor_row<n && negihbor_col>=0 && negihbor_col<m && vis[negihbor_row][negihbor_col]==0 &&  grid[negihbor_row][negihbor_col]==1)
                 {
                        q.push({{negihbor_row,negihbor_col},Curr_time+1});
                      
                        vis[negihbor_row][negihbor_col]  = 2 ;
                        count++;
                 }   


                

            }
        }
        // cout<<countFresh<<" "<<count<<endl;
        if(countFresh!=count) return -1;
        else return mx_time ;
    }
};
