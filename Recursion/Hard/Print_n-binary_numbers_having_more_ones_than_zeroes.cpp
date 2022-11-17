// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:	
      
    vector<string>ans;
    int n;
    void generate(int one,int zero ,string &curr){
       if(curr.size()==n){
           ans.push_back(curr);
           return ;
       }
        if(curr.size()>n){
        //   ans.pb(curr);
           return ;
       }
       if(one<n){
            curr.push_back('1');
           generate(one+1,zero,curr);
            curr.pop_back();
       }
       if(zero<one){
           curr.push_back('0');
           generate(one,zero+1,curr);
            curr.pop_back();
           
       }
       
       
    }
	vector<string> NBitBinary(int N)
	{
	    int i = (N+1)/2;
	    string curr ="";
	    n = N;
	   // for(i ; i <= N ; ++i)
	    generate(0,0,curr);
	    return ans;
	    // Your code goes here
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends
