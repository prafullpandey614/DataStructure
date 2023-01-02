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
int n = 3e5 + 5,m;
v64 power2(n,1);//initialize powers of 2 with 1's
vv64 adj(n);
vector<int>color(n,-1);
vector<bool>vis(n);
ll c0,c1;

void dfs(int ver){
	vis[ver]  = 1;
	for(int u:adj[ver]){
		if(color[u]==color[ver]){ //discrepancy
			color[ver] = 3; 
			continue ;
		}
		if(!vis[u]){
			if(color[ver]==1) color[u] = 2;
			else if(color[ver]==2) color[u]=1;
			else color[u] = 1;
			dfs(u);
		}
	}
	
}

void createGraph(){
	cin>>n;
	forn(i,n) adj[i].clear(),vis[i] = 0 ,color[i] = -1;
	v32 v(n);
	forn(i,n) cin>>v[i];
	forn(i,n-1){
		if(v[i]!=v[i+1]){
			adj[i].pb(i+1);
			adj[i+1].pb(i);
		}
	}
	if(v[0]!=v[n-1]){
		adj[0].pb(n-1);
	}
	forn(i,n) if(!vis[i]) color[i]=1,dfs(i);
	int max_color = 1;
	forn(i,n) max_color = max(max_color,color[i]);
	cout<<max_color<<ln;
	forn(i,n) cout<<color[i]<<" ";
	// count<<ln;
}
int main()
{
	
 fast_cin();
 ll t=1;
 cin >> t;
 
 for(int it=1;it<=t;it++) {
	 createGraph();
	
 }
 return 0;
}
