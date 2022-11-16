#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	 
	while(t--){
	   //pf.clear();
	   
	    long long int n,q;
	    cin>>n>>q;
	    long long x;
	    vector<vector<int>>pf(60,vector<int>(n+1,0));
	   // std::vector<long long int>v(n);
	    for(int i = 0 ; i < n ; ++i){
	       // cin>>v[i];
	       cin>>x;
	       //v[i]=x;
	       int k= 0;
	       while(x>>k){
	           pf[k][i]= (x>>k)&1;
	           k++;
	       }
	       // v[i] = (x&(1<<k));
	    }
	    for(int i = 0; i < 60 ; ++i){
	        for(int j =0 ; j <n ; ++j){
	            pf[i][j+1] += pf[i][j];
	        }
	    }
	    
	    while(q--){
	        int k,l,r,p,q;
	        cin>>k>>l>>r>>p>>q;
	       // for(int i=l-1;i<r ;++i)
	       l--;r--;p--;q--;
	       
	       long long count_set_left = (pf[k][r]-pf[k][l-1]);
	       long long count_set_right  = (pf[k][q]-pf[k][p-1]);
	       
	       cout<<count_set_left*(q-p+1 - count_set_right)+count_set_right*(r-l+1-count_set_left)<<endl;
	       //int count_set_bits = 0;
	       //long long c=p,d=l;
	       //long long ht = (1<<k);
	       //while(l<=r){
	       //    v[l] = ((v[l])&(ht));
	       //    if(v[l]^ht==0){
	       //        count_set_bits++;
	       //    }
	       //    l++;
	       //}
	       //long long count_unset_bits = 0;
	       //while(p<=q){
	       //    v[p] = (v[p]&(ht));
	       //    if(v[p]^ht!=0){
	       //        count_unset_bits++;
	       //    }
	       //    p++;
	       //}
	       //cout<<(count_unset_bits*count_set_bits)+(r-d+1-count_set_bits)*(q-c+1-count_unset_bits);
	       //cout<<endl;
	    }
	}
	return 0;
}
