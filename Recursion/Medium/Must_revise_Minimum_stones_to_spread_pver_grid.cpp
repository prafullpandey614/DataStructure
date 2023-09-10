class Solution {
public:
    int solve(int ind,vector<vector<int>>& emp,vector<vector<int>>& giv){
        if(ind==emp.size()) return 0;
        int ans = 100;
        
            for(int j=0; j<giv.size(); ++j){
                if(giv[j][2]>1){
                    giv[j][2]-=1;
                    ans = min(ans,abs(emp[ind][0]-giv[j][0])+abs(emp[ind][1]-giv[j][1])+solve(ind+1,emp,giv));
                    giv[j][2]+=1;
                }
            }
        
        return ans ;
        
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>>emp ;
        vector<vector<int>>giv ;

        
        for(int i = 0; i<3; ++i){
            for(int j =0 ; j<3 ; ++j){
                if(grid[i][j]==0){
                 emp.push_back({i,j});
                }
                if(grid[i][j]>1){
                    giv.push_back({i,j,grid[i][j]});
                }
            }
        }
        return solve(0,emp,giv);
        
    }
};
