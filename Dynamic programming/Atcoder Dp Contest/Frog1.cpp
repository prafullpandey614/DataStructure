#include <bits/stdc++.h>
using namespace std;
 std::vector<int>v ;
 vector<int>dp;
 int mCost(int n){
   if(n==0)  return 0;
   if(n==1)  return abs(v[0]-v[1]);
   if(dp[n]!=-1) return dp[n];
   int cost1 = mCost(n-1)+abs(v[n]-v[n-1]);
   int cost2 = mCost(n-2)+ abs(v[n]-v[n-2]);
   return dp[n]= min(cost2,cost1);
    
}
int main() {
    int n;
    cin>>n;
    v.resize(n);
    dp.resize(n+1,-1);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    
    cout<<mCost(n-1)<<endl;
	return 0;
}
