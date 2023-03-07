class Solution {
public:
    bool check(long long mid,vector<int>&time,int tt){
        long long  count = 0 ;
        for(int i = 0; i <time.size() ; ++i){
            count+= (mid/time[i]);
            if(count>tt) return 1;
        }
        if(count>=tt) return 1;
        return 0 ;
        
    }
    long long minimumTime(vector<int>& time, int tt) {
        sort(time.begin(),time.end());
        long long hi = tt*1LL*time[time.size()-1];
        long long lo = 0;
        while(lo<hi){
            long long mid = (hi+lo)>>1;
            if(check(mid,time,tt)){
                hi = mid ;
            }
            else{
                lo = mid+1;
            }
        }
        return min(lo,hi) ;
    }
};
