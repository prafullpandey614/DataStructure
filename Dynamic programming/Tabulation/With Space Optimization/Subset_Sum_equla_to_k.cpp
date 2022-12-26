#include <bits/stdc++.h> 


bool subsetSumToK(int n, int k, vector<int> &arr) {
   
  vector<bool>prev(k+1,0),curr(k+1,0);
    prev[arr[0]] = 1;
    curr[0] = 1;
    prev[0]  = 1;
    for(int i = 1; i<n; ++i){
      for(int tar=1;  tar<=k ; ++tar){
          bool op1 = 0 ;
          if(tar>=arr[i]){
             op1 = prev[tar-arr[i]];
          }
          curr[tar] = prev[tar] | op1 ; 
      }
        prev = curr; 
        
    }
    
    return prev[k];
}
