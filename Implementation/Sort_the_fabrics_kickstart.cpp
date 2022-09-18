#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
bool cmp1(pair<string,pair<int, int>>& a,
        pair<string,pair<int, int>>& b)
{
     if(a.second.first!=b.second.first) return (a.second.first < b.second.first);
     else return (a.second.second <b.second.second);
}
bool cmp2(pair<string,pair<int, int>>& a,
        pair<string,pair<int, int>>& b)
{
    if(a.first != b.first)   return (a.first < b.first);
   else  return ((a.second.second < b.second.second));
    //  return a.first<b.first;
}
int main() {
  int t;
  cin>>t;
  for (int j = 0; j < t; j++) {

      int n;
      cin>>n;
    //   vector<string>ap;
    //   vector<string>ad;
    //   vector<pair<string,int>>mp;
    //   vector<pair<int,int>>md;
    //   map<int,string>an;
        vector<pair<string,pair<int,int>>>ans,ans2 ;
      for (int i = 0; i < n; i++) {
         string a;
      int b,c;
      cin>>a>>b>>c;
      ans.pb({a,{b,c}});
      mp.pb({a,c});
   
      md.pb({b,c});
      an[c] = a;
      
      }
      ans2 = ans;
    //   sort(mp.begin(),mp.end());
    //   sort(md.begin(),md.end());
      sort(ans.begin(),ans.end(),cmp1);

      sort(ans2.begin(),ans2.end(),cmp2);
      int count = 0;
    
    
      for(int i = 0; i < n ;++i){
        
        //   cout<<ap[i]<<" "<<ad[i]<<endl;
          if(ans[i]==ans2[i]) count++;
          
      }
      
      cout<<"Case #"<<j+1<<": "<<count<<endl;
  }

}
