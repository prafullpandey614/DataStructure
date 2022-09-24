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
 

void solve(){

  ll n ,q;
  cin>>n>>q;
  v64 v(n);
  forn(i,n) cin>>v[i];

  multiset<int>st;
  forn(i,n-1){
      st.insert(v[i+1]-v[i]);
  }
//   ll goodness = *st.begin();
//   dbg(goodness);
   while(q--){
       ll a,b;
       cin>>a>>b;
       a--;
    //    v[a] = b;
     if(a-1>=0){
       st.erase(st.find(v[a]-v[a-1]));
       st.insert(b-v[a-1]);
     }
     if(a+1<n){
         st.erase(st.find(v[a+1]-v[a]));
         st.insert(v[a+1]-b);
     }
     v[a] =b;
     ll ans = *st.begin();
     if(ans<0)
     cout<<abs(ans)<<ln;
     else cout<<0<<ln;

   }


}
int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
// cout << "Case #" << it+1 << ": ";
solve();
 }
 return 0;
}
