#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
 
      int n,m;
      cin>>n>>m;
      bool flag = 0;
      for(int i = 1; i <= n ;++i){
          for (int j= 1; j <= m; j++) {
             if(i&1){
                 cout<<'#';
             }
             else if(flag==0 && j==m){
                 cout<<'#';
                
             }
             else if(flag && j==1){ cout<<'#'; }
             else cout<<'.';
          }
           if(i%2==0){
           if(flag) flag=0;
           else flag=1;
           }
          cout<<endl;
      }
      
      
      
      
 return 0;
}
