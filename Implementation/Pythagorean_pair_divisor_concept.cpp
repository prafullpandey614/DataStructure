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
  
  
//   (2^m (a))^2 + (2^m  (b))^2  =  n = 2^(2m) (odd divisors)
  
  
    ll n;
    cin>>n;
  ll j = 0 , sum = 0 , sum2 = 0;
  ll even = 0;
  while(n%2==0) {
      even++; // counting the even divisors 
      n/=2;
  }
  
  if(even&1){
      even--;
      n*=2;
  }
  even = 1<<(even/2); // distributing the even powers to both a and b
    for(int j = 0 ; j *j<=n ;++j){
        sum = n-(j*j); 
        sum2 = sqrt(sum);
        if(sum==sum2*sum2) {
            
           sum = j;
           cout<<even*j<<" "<<even*sum2<<ln; //multiplying the odd divisors with the even ones
           return ;
            
            
        }
       
        
    }
    // if(trip==n) cout<<i<<" "<<k<<ln;
    cout<<-1<<ln;
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
