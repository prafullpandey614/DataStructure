//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int cnt= 1, bnt = 1 ;
    char curr = str[0] ;
    for(int i = 1; i < str.size(); ++i){
        if(str[i]!=curr){
            curr= str[i];
            cnt++;
        }
      
        
    }
   
    return ((cnt)>>1) + 1 ;
  
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends
