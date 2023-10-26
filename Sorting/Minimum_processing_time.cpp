class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end()) ;
        sort(p.begin(),p.end(),greater<int>());
   
        
        int i = 3 ;
        int ans = 0 ;
        for(int  x: p ){
            ans = max(ans,x+tasks[i]);
            i+=4;
        }
        return ans ;
        
        
        // return 1;
        return max(tasks[tasks.size()-1]+p[p.size()-1],tasks[3]+p[0]);
    }
};
