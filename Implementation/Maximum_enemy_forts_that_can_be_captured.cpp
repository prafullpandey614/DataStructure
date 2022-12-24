class Solution {
public:
    int captureForts(vector<int>& forts) {
        int m =0;
        int n = forts.size();
        int cnt1=  0 , cnt2 = 0;
        for(int i = 0;  i< n ; ++i){
            if(forts[i]==1){
                m = max(m,cnt2-1);
                cnt2=0;
                cnt1=1;
                // i++;
            }
            else if(forts[i]==-1){
                m = max(m,cnt1-1);
                cnt1=0;
                cnt2=1;
                // i++;
            }
            else{
                if(cnt1) cnt1++;
                if(cnt2) cnt2++;
            }
        }
       
        return m;
    }
};
