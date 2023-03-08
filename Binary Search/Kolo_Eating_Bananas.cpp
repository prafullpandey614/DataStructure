class Solution {
public:
    bool check(int mid,vector<int>&p,int h){
        int hrs = 0 ;
        for(int i = 0 ; i < p.size(); ++i){
            hrs+= (mid-1+p[i])/mid ;
        }
        return hrs<=h ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // int hi = 1e9 ;
        int hi = -1; 
        for(int x:piles){
            hi = max(x,hi);
        }
        int lo = 1;
        while(hi>lo){
            int mid = (hi+lo)>>1;
            if(check(mid,piles,h)){
                hi = mid ;
            }
            else {
                lo = mid+1;
            }
        }
        return lo ;
    }
};
