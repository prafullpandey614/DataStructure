int frogJump(int n, vector<int> &h)
{
    // Write your code here.
    dp.clear();
    
    dp.resize(h.size()+10,-1);
    dp[0] = 0 ; //base case analogy with recursion 
    int first_step = INT_MAX, second_step= INT_MAX;
    for(int i = 1 ; i  < h.size(); ++i){
         first_step = dp[i-1]+abs(h[i]-h[i-1]);
        if(i>1){
            second_step  = dp[i-2]+abs(h[i]-h[i-2]);
        }
        dp[i] = min(first_step,second_step);
    }
    return dp[h.size()-1];
}
