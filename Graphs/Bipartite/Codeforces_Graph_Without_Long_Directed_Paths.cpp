// Problem Link  : https://codeforces.com/contest/1144/problem/F
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
vector<int>color;
vector<bool>vis;
int hg;
int ans ;
bool dfs(int ver,vector<int>g[]){
	vis[ver] = 1;
	// bool flag = 1;
	for(auto child:g[ver]){
		if(color[child]==color[ver]) return 0 ;
		if(!vis[child]){
			color[child]  = !color[ver];
			if(!dfs(child,g)) return  0;
		}
	}
	return 1 ;
}
void solve(){
    int n;
    int m ;
	cin>>n>>m;
	hg = m ;
	
	color.resize(n+1,-1);
	vis.resize(n+1,0);
	int x,y;
	vector<int>g[n+1];
	vector<vector<int>>edges;
	forn(i,m){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
		edges.push_back({x,y});
	}
	color[1] = 1;
	if(dfs(1,g)){
		cout<<"YES"<<ln;
		string ans= "";
		int u,v;
		for(auto x:edges){
			u = x[0] ; v = x[1];
			if(color[u]==1){
				ans.push_back('1');
			}
			else ans.pb('0');
		}
		cout<<ans<<ln;
	}
	
	else cout<<"NO"<<ln;
	
}
int main()
{
 fast_cin();
 ll t=1;
//  cin >> t;
 for(int it=1;it<=t;it++) {

solve();
 }
 return 0;
}
