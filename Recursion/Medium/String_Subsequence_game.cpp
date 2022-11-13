//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    set<string>st;
    void rec(string ip,string op){
        if(ip.length()==0){
            int n = op.size()-1;
            if((op[n]!='a' && op[n]!='e' && op[n]!='i' && op[n]!='o' &&op[n]!='u') && (op[0]=='a' || op[0]=='e' || op[0]=='i' || op[0]=='o' ||op[0]=='u'))
            st.insert(op);
            return ;
        }
        
        char t = ip[0];
        
        ip.erase(ip.begin()+0);
        op.push_back(t);
        rec(ip,op);
        op.pop_back();
        rec(ip,op);
        
    }
    set<string> allPossibleSubsequences(string S) {
        // code here
        st.clear();
        rec(S,"");
        return st;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
