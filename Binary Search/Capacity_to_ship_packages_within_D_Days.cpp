class Solution {
public:
bool check(int m,vector<int>&wt, int d){
    bool ans=  0 ;
    int i = 0 ; 
    int fd = m ;
    int req = 1 ;
    int curr=0 ; 
    for(int i = 0 ;i < wt.size() ; ++i){
        if(curr+wt[i]>fd){
            req++;
            curr=  wt[i];
        }
        else curr+=wt[i];
    }
    if(curr>m) req++;
    return req<=d;    
}
    int shipWithinDays(vector<int>& wt, int d) {
        int hi = accumulate(wt.begin(),wt.end(),0);
      int lo = 0 ;    for(int x:wt) lo = max(x,lo);
        int sum = hi ; 
       
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            cout<<hi<<" "<<mid<<" "<<lo<<endl;
            if(check(mid,wt,d)==true){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        
        if(check(lo,wt,d)) return lo;
        return hi; 
        return lo ;
        
    }
};
