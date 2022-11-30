//Codechef Problem
//problem link : https://www.codechef.com/problems/MUSROD?tab=statement

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<int,int>x,pair<int,int> y){
    return x.first*y.second > x.second*y.first ;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll int n;
	    cin>>n;
	    vector<pair<ll,ll>>v(n);
	    for (int i = 0; i < n; i++) {
	        /* code */
	        cin>>v[i].first ;
	   
	    }
	    for (int i = 0; i < n; i++) {
	        /* code */
	        cin>>v[i].second ;
	    }
	    sort(v.begin(),v.end(),cmp);
	    long long ans ;
	    ans = 0 ; 
	    ll x = 0;
	    for(int i = 0 ; i < n ;++i){
	        ans+= (x*v[i].second) ;
	        x+=v[i].first ;
	    }
	    cout<<ans<<"\n";
	   // std::vector<long long >prod ;
	   
	    
	}
	return 0;
}
