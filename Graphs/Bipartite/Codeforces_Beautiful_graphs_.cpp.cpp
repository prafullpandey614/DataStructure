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

bool dfs(int ver){
	vis[ver] = 1;
	for(int child:adj[ver]){
		if(color[child]==color[ver]) return 0 ;
		if(!vis[child]){
			color[child]  = !color[ver];
			if(color[child]) c1++;
			else c0++;
			if(!dfs(child)) return  0;
		}
	}
	return 1 ;
}

void solve(){
	
	ll ans=  1;
	forsn(i,1,n+1){
		if(!vis[i]){
			c0 = 0 ;
			c1 = 1 ;
			color[i] = 1;
			if(!dfs(i)){
				ans = 0 ;
				break ; 
				
			}
			else{
				ans  = (ans*(power2[c0]+power2[c1])%MOD)%MOD;
			}
		}
	}
	cout<<ans<<ln;
}
int main()
{
	
 fast_cin();
 ll t=1;
 cin >> t;
 for (int i = 1;i<n;i++)power2[i] = (power2[i - 1] * 2)%MOD;
 for(int it=1;it<=t;it++) {
cin>>n>>m;
	for (int i = 1;i<=n;i++)adj[i].clear(),color[i] = -1,vis[i] = false;
	 while (m--){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v),adj[v].pb(u);
        }
	solve();
 }
 return 0;
}
