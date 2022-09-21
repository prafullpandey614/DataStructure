#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
 
      int a,b;
      cin>>a>>b;
      int arr[a];
      int sum = 0;
      for (int i = 0; i < a; i++) {
        cin>>arr[i];
        sum+=arr[i];
      }
      int inter = a-1;
      if((inter*10 + sum)<= b){
          if((inter*10 + sum)== b) cout<<inter*2<<endl;
          else cout<<inter*2 + (b-(inter*10 + sum))/5<<endl;
      }
      else cout<<-1<<endl;
      
      
      
      
 return 0;
}
