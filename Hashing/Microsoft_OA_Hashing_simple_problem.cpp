Problem Link : https://www.desiqna.in/13267/microsoft-coding-oa-sde-1-may-3-2023 

#include <bits/stdc++.h>
using namespace std ;

int digit_sum(int n){
    int sum = 0 ;
    while(n>0){
        int rem = n%10 ;
        n = n/10;
        sum+=rem ;
    }
    return sum ;
}

int main() {
    // Write C++ code here
    int n ;
    cin>>n;
   int arr[n] ;
   for(int i =0 ; i < n ; ++i) cin>>arr[i] ;
   unordered_map<int,priority_queue<int>>mp ;
   for(int i =0 ; i<n; ++i){
       mp[digit_sum(arr[i])].push(arr[i]);
   }
   int sum = 0; 
   for(auto x:mp){
       if(x.second.size()>=2){
           int curr = x.second.top();
           x.second.pop();
           curr+=x.second.top();
           sum = max(sum,curr);
       }
   }
   cout<<(sum==0 ? -1 : sum)<<endl;

    return 0;
}
