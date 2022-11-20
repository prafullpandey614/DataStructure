int frogJump(int n, vector<int> &h)
{
 
    int prev1= 0 ;    // Space Optimization
    int prev2= 0;    // Space Optimization
    int first_step = INT_MAX, second_step= INT_MAX;
    int ans;
    for(int i = 1 ; i  < h.size(); ++i){
         first_step = prev1+abs(h[i]-h[i-1]);
        if(i>1){
            second_step  = prev2+abs(h[i]-h[i-2]);
        }
        
        ans = min(first_step,second_step);
        prev2 = prev1;
        prev1 =  ans ;
        
      
    }
    return ans;
}
