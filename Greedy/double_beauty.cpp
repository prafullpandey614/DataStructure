#include <bits/stdc++.h>
using namespace std;
int main() {
	
	int t;
	cin>>t;
	while(t--){
		cin>>m>>n;
		vector<int>arr(m);
		for(int i = 0; i < m; ++i) cin>>arr[i];
		sort(arr.begin(),arr.end(),greater<int>());
		int sum = 0 ;
		for(int i = 0; i < m ;++i){
			if(i<n){
				sum+=arr[i]*2;
			}
			else break;
		}
		cout<<sum<<endl;

	}

	}
