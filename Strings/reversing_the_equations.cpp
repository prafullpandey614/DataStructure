//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


 #include<bits/stdc++.h>
class Solution
{
  public:
    string reverseEqn (string s){
        string ans="",temp="";
        int n=s.size();
        for(int i=n;i>=0;i--){
            int a=s[i];
            if(!(a>=48 && a<=57)) {
                if(temp.size()!=0){
                    ans+=temp;
                }
            temp="";
            ans+=s[i];  
            }
            else{
                temp=s[i]+temp;
            }
        }
        if(temp.size()!=0){
            ans+=temp;
        }
    return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
