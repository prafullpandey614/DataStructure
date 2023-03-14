class Solution {
public:
    int alice = 0 ;
    vector<int>ans ;
    bool flag = 0 ;
    void dfs(int ind,int n,vector<int>&a,vector<int>&b,int score){
        // if(flag) return ;
        
        if(alice<score){
                // flag = 1;
                ans = b; 
                alice = score ;
                return ;
        }
        if(ind>11 || n<=0) {
           return ;
        }
            dfs(ind+1,n,a,b,score);
            
            b[ind] = a[ind]+1 ;
            if(n-b[ind]>=0)
            dfs(ind+1,n-b[ind],a,b,score+ind) ;
            b[ind] = 0 ;
       
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
       int i = 0 ;
        for(int x:aliceArrows){
            alice+= x*i;
            i++;
        }
        alice = 0  ;
        vector<int>b(12,0);
        dfs(0,numArrows,aliceArrows,b,0);
        int arr = accumulate(ans.begin(),ans.end(),0);
        if(arr<numArrows){
            ans[0] = numArrows-arr ;
        }
        return ans ;
    }
};
