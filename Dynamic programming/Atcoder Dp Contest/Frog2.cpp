#include <bits/stdc++.h>
using namespace std;
 std::vector<int>v ;
 vector<int>dp;
 int  k;
 int mCost(int n){
   if(n==0)  return dp[n]=0;
   //if(n==1)  return abs(v[0]-v[1]);
   if(dp[n]!=-1) return dp[n];
   int cost=INT_MAX;
   for(int i=1; i<=k ; ++i){
       if(n>=i)
      cost = min(cost,mCost(n-i)+abs(v[n]-v[n-i]));
   }
 
   return dp[n]= cost;
    
}
int main() {
    int n;
    cin>>n;
    cin>>k;
    v.resize(n);
    dp.resize(n+10,-1);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    
    cout<<mCost(n-1)<<endl;
	return 0;
}
