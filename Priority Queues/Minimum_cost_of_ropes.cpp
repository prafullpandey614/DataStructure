//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        // sort(arr,arr+n);
        // priority_queue<pair<int> , vector<pair<int>>, greater<pair<int>>>pq;
        priority_queue<long long int,vector<long long int> , greater<long long int>>mhp;
        for(long long int i = 0; i < n ;++i){
            mhp.push(arr[i]);
        }
        long long sum = 0,ngo = 0;

        while(mhp.size()>1){
           long   long int curr = mhp.top();
             mhp.pop();
             long long int currto = mhp.top();
             mhp.pop();
             mhp.push(curr+currto);
             sum+=curr+currto ;
           
             
        }
        
        return sum;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
