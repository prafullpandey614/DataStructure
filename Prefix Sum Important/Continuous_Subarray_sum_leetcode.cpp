 bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp; //this will store index with prefix sums 
        int pf = 0 ;
        for(int  i  = 0 ; i<  nums.size() ;++i){
            pf+=nums[i];
            pf%=k;
            if(pf==0 && i) return 1; 
            if(mp.find(pf)!=mp.end()){
                if(i-mp[pf]>1) return 1; // if the diffrence of current index with the found index is greater than 1 that means both these indexes are not same
            }
            else mp[pf]  =i ;
        }
    return 0; 
    }
