#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<int>v(n);
	// unordered_map<int,int>mp,tp;
	vector<int>mp(1000001,0);
	
	int mx = INT_MIN ;
	for(int i = 0 ;i < n ; ++i) cin>>v[i],mp[v[i]]++;
	vector<long long>hsh(1000001,0);
	
	for(int i =0 ; i < 1e6+1; ++i){
		hsh[mp[i]] += mp[i]*i;
	}
	for(int i = 1; i < hsh.size(); ++i){
		hsh[i] +=hsh[i-1];
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		l--;
		if(l<0){
			cout<<hsh[r]<<endl;
		}
		else cout<<hsh[r]-hsh[l]<<endl;
	}

}
