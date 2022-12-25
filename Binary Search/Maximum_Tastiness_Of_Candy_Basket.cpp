class Solution {
public:
    bool check(int ver,vector<int>& price,int k){
        int j = 0 ;
        int len = 1;
        for(int i = 1; i< price.size(); ++i){
            int diff = price[i]-price[j];
            if(diff>=ver){
                len++;
                j= i ;
                  // if(len>=k) return 1;
            }
          
        }
        return len>=k ;
    }
    int maximumTastiness(vector<int>& prices, int k) {
        int n = prices.size();
        sort(prices.begin(),prices.end());
        
        int lo = 0 ; 
        int hi = prices[n-1] - prices[0];
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            bool pass = check(mid,prices,k);
            if(pass){
                ans = max(mid,ans);
                lo= mid+1;
            }
            else{
                hi=  mid-1;
                
            }
            
        }
        return ans ;
    }
};
