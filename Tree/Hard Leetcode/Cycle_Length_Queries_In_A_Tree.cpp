class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans ;
        int x = 0;
        int y = 0;
        for(auto q:queries){
            int left =  q[0];
            int right = q[1];
            x = 0 ; // for tracking the left path to reach LCA
            y = 0 ; // for tracking the right path to reach LCA
            while(left!=right){
                if(left>right){
                    x++;
                    left/=2; //dividing by two because every parent is almost double of their child
                }
                else {
                    right/=2; //dividing by two because every parent is almost double of their child
                    y++;
                }
            }
            ans.push_back({x+y+1});
        }
    return ans ;
    }
};
