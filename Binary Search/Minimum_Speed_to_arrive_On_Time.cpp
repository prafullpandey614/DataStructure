class Solution {
public:
bool check(int speed,vector<int>&dist,const double hour){
   double time = 0;
        for (int i = 0; i < dist.size() - 1; ++i)
            time += ((dist[i] + speed - 1) / speed);
        
        time += ((double)dist.back()) / speed;
        return time <= hour;
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
      
        int lo = 1;
        int hi = 1e7;
        int N = dist.size();
        if (hour <= (double)(N - 1))
            return -1;

       
        while(hi>lo){
            int mid = (hi+lo)>>1;
            if(check(mid,dist,hour)){
                hi = mid ;
            }
            else {
                lo = mid+1 ;
            }
        }
        // if(check(min(hi,lo),dist,hour)) return min(hi,lo);
        // if(check(lo,dist,hour)) return lo;
        // if(check(hi,dist,hour)) return hi ;
        return hi ;
        return -1;

    }
};
