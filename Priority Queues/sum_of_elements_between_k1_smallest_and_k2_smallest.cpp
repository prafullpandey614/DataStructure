//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long k1, long long k2)
    {
        // Your code goes here
        priority_queue<long long int>pq;
        for(long long int i = 0; i < N ;++i){
            pq.push(A[i]);
            if(pq.size()>k1){
                pq.pop();
            }
        }
        long long low = pq.top();
        while(!pq.empty()) pq.pop();
        for(long long int i = 0; i < N ;++i){
            pq.push(A[i]);
            if(pq.size()>k2){
                pq.pop();
            }
        }
        long long sum = 0 ;
        long long high = pq.top();
        for(long long int i = 0 ; i <N ;++i){
            if(A[i]<high && A[i]>low) sum+=A[i];
        }
        return sum ;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends
