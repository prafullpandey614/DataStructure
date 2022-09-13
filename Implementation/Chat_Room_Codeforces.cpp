#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
	// your code goes here

	string s,ans="hello";
	cin>>s;
	int j = 0;int pass=0;
	
for (int i = 0; i < s.size(); i++) {
    
   if(s[i]==ans[j]){
       j++;
       pass++;
   }
   if(pass==5)break;
   
}
if(pass==5) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
