
int getMaxCandidate(map<int,int>&mp,int k){
    auto it = mp.lower_bound(k);
    if(it==mp.begin()) return 0;
    it--;
    return it->second ;
}
void insert(map<int,int>&mp,int dpi,int k){
    if(mp[k]>=dpi) return ;
    auto it = mp.lower_bound(k);
    it++;
    while(it!=mp.end() && it->second<=dpi){
        auto temp = it;
        it++;
            mp.erase(temp);
        
    
    }
    mp[k]= dpi ;
}
int Solution::lis(const vector<int> &A) {
    vector<int>dp(A.size()+1,0);
    dp[0] = 1;
    int n = A.size();
    map<int,int>mp; // key = element value = length of longest
    mp[A[0]] = dp[0];
    for(int i = 0 ;i <n ; ++i){
        dp[i] = 1 + getMaxCandidate(mp,A[i]);
        insert(mp,dp[i],A[i]);
    }
    return *max_element(dp.begin(),dp.end());
}
