class Solution {
public:
  
    int climbStairs(int n) {
       
        if(n==1) return 1;
        if(n==2) return 2;
        int p1 = 1;
        int p2 = 2;
        int curr=p1+p2;
        int temp ;
        for(int i = 3; i<=n ; ++i){
            curr = p1 + p2 ;
            temp = p2 ;
            p2 = curr ;
            p1 = temp;
        }
        return curr;
        
    }
};
