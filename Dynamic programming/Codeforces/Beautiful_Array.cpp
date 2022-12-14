contest link : https://codeforces.com/contest/1155
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
 
const int mod = 1e9+7;
void solve(){
    ll n,x;
    cin>>n>>x;
    
    v64 v(n);
    forn(i,n) cin>>v[i];
    ll dp[n+1][2][2];
    memset(dp, 0, sizeof(dp));
    dp[0][1][0] = v[0];
    dp[0][1][1] = v[0]*x;
   
    ll ans = max(0LL,max(1LL*v[0],x*v[0]));
    forsn(i,1,n){
        dp[i][1][0] = max(dp[i-1][1][0]+v[i],v[i]); 
        dp[i][1][1] = max(v[i]*x,v[i]*x + max(dp[i-1][1][1],dp[i-1][1][0]));
        dp[i][0][0] = max(v[i],v[i]+max(dp[i-1][1][1],dp[i-1][0][0]));
        ans= max(ans,max(dp[i][1][1],max(dp[i][1][0],dp[i][0][0])));
        
        
    }
    cout<<ans;
}
int main()
{
 fast_cin();
 ll t;
 t=1;
//  cin >> t;
 for(int it=1;it<=t;it++) {
// cout << "Case #" << it+1 << ": ";
solve();
 }
 return 0;
}
