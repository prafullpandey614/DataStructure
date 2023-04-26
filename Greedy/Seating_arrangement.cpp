//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& s){
        // Write your code here.
         if(s[0]==0 && s[1]==0)
        {
            n--;
            s[0]=1;
        }
        for(int i=1;i<m-1;i++)
        {
            if(s[i]==0)
            {
                if(s[i+1]==0 && s[i-1]==0)
                {
                    n--;
                    s[i]=1;
                }
            }
        }
        if(s[m-2]==0 && s[m-1]==0) n--;
        return (n<=0);
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends
