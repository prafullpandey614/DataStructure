//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   
    long long solve(int n, int k, vector<long long> arr) {
        // code here
       if(k>=n){
            return arr[n-1];
        }
        vector<long long> pfsum=arr;
        long long sum=0;
        for(auto x:arr){
            sum+=x;
        }
        pfsum.push_back(sum);
        for(long long i=k+1;i<=n;i++){
            sum+=pfsum[i-1];
            sum-=pfsum[i-k-1];
            pfsum.push_back(sum);
        }
        return pfsum[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
