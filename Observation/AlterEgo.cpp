#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    long long sum = 0 ;
	    std::vector<int>od,even ;
	    for(int i = 0 ; i< n ; ++i){
	        cin>>arr[i];
	        sum+=arr[i];
	        if(arr[i]&1){
	            od.push_back(arr[i]);
	        }
	        else{
	            even.push_back(arr[i]);
	        }
	    }
	    if(sum&1){
	        cout<<"-1"<<endl;
	        continue ;
	    }
	    sort(od.begin(),od.end());
	    sort(even.begin(),even.end());
	    vector<int>ans(n) ;
	    int i ;
	    int j = 0; 
	    for( i = 0 ; i< od.size()/2; ++i){
	        ans[j] = (od[i]+od[od.size()-1-i])/2;
	        ans[j+(n/2)]  = (od[od.size()-1-i]-ans[j]);
	        j++;
	    }
	    for( i = 0 ; i< even.size()/2; ++i){
	        ans[j] = (even[i]+even[even.size()-1-i])/2;
	        ans[j+(n/2)]  = (even[even.size()-1-i]-ans[j]);
	        j++;
	    }
	    for(auto x:ans){
	        cout<<x<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}
