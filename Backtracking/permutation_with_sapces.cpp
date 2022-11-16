//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<string>ans;
    void rec(int ind,string curr, string &s){
        if(ind==s.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(s[ind]);
        if(ind!=s.size()-1)
        curr.push_back(' ');
        rec(ind+1,curr,s);
        if(ind!=s.size()-1)
        { curr.pop_back();
        rec(ind+1,curr,s);
        }
       
    }
    vector<string> permutation(string S){
        // Code Here
        string curr="";
        rec(0,curr,S);
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends
