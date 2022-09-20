#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
bool cmp(pair<int,int>&p1,pair<int,int>&p2){
    if(p1.first==p2.first) 
    return p1.second<p2.second;
    // else return p1.first>p2.first;
}
int main() {
    int st;
    cin>>st;
    int n;
    cin>>n;
    bool flag = 0;
    multimap<int,int>v;
     int x,y;
    for (int i = 0; i < n; i++) {
      
       cin>>x>>y;
       v.insert({x,y});
       
    }
  
  
    for(auto x:v){
        if(st<=x.first){
            flag = 1;
            break ;
        }
        else {
            st+=x.second ;
            
        }
    }
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    
    
 return 0;
}
