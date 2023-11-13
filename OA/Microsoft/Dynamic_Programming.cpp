// Problem Link : https://leetcode.com/discuss/interview-question/4280880/Microsoft-OA-help

#include <bits/stdc++.h>
using namespace std ;
int merge(int x,int y){
    int cnt = 1 ;
    int mnt = y ;
    while(mnt>0){
        mnt/=10;
        cnt*=10;
    }
    return x*cnt+y;
}
int solve(vector<int>&v,int ind){
    if(ind<0) return 0;
    if(ind==0) return v[ind];
    //don't merge
    int ans=  v[ind] + solve(v,ind-1) ;
    //merge
    ans = max(ans,merge(v[ind-1],v[ind])+solve(v,ind-2));
    return ans;
    
}
int main() {
    // Write C++ code here
    vector<int>v = {1,2,3,4,5,6};
    std::cout <<solve(v,5);

    return 0;
}
