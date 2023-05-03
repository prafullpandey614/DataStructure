//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
          unordered_map<string,int> mp;
        
        for(auto i:arr)
        {
            string s=i;
            reverse(s.begin(),s.end());
            if(mp.find(s) != mp.end()) mp.erase(s);
            else mp[i]=1;
        }
        
        if(mp.size() == 0)return true;
        
        if(mp.size() == 1)
        {
            for(auto i:mp)
            {
                string s = i.first;
                string rs = i.first;
                reverse(rs.begin(),rs.end());
                if(s == rs)return true;
                else return false;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends
