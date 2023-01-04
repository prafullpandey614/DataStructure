#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
// bool cats[n] ;
int n  = 2*1e5+10 ,m = 2*1e5+10;
v32 vis(n);
vv32 adj(n);
bool isCycle=  1;
void dfs(int ver){
	vis[ver] = 1;
	if(adj[ver].size()!=2) isCycle = false ;
	bool b = 1;
	for(auto ch:adj[ver]){
		
		if(!vis[ch]) {
			
			dfs(ch);
			
		}
	}
	// isCycle = 1;
}
void solve(){
	int n,m;
	cin>>n>>m;
	forn(i,m){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int cnt = 0 ;
	forsn(i,1,n+1){
		if(!vis[i]){
			isCycle=  true;
			dfs(i) ;
			if(isCycle) cnt++;
		}
		
	}
	cout<<cnt<<ln;
}
int main()
{
	
 fast_cin();
 ll t=1;
//  cin >> t;
 
 for(int it=1;it<=t;it++) {
	//  createGraph();/
	
	solve();
	
 }
 return 0;
}
