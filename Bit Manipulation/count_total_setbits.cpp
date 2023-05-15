//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findLargestPower(int n)
{
	int x = 0;
	while ((1 << x) <= n)
		x++;
	return x - 1;
}

int countBits(int n)
{
	if (n <= 1)
		return n;
	int x = findLargestPower(n);
	return (x * pow(2, (x - 1))) + (n - pow(2, x) + 1)
		+ countBits(n - pow(2, x));
}
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
