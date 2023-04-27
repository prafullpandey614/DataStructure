//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int pref[N+1] = {0};
        int sum = 0,ans = 0;
        unordered_map<int,int>mp;
        for(int i = 0 ;i  < N ; ++i){
            sum+=A[i];
            if(sum==K) ans = max(ans,i+1);
            if(mp.find(sum-K)!=mp.end()){
                ans = max(ans,i-mp[sum-K]);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=  i;
        }
        return ans ;
       
        return ans ;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
