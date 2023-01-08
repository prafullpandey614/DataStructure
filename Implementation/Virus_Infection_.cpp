// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(string s, int k){
        // code here
        for(int i = 0 ; i <s.size(); ++i){
            if(s[i]=='1'){
                s[i]='2';
                int cnt = 0;
                i++;
                while(i<s.size() && cnt<k){
                    if(s[i]=='1') {
                        s[i]='2';
                        cnt=0;
                    }
                    if(s[i]=='0'){
                        s[i]='1';
                        cnt++;
                    }
                    
                    i++;
                }
                i--;
            }
        }
        for(int i = s.size()-1; i>=0 ; --i){
            if(s[i]=='2'){
                s[i]='1';
                int cnt = 0;
                i--;
                while(i>=0 && cnt!=k){
                    if(s[i]=='2'){
                        cnt = 0 ;
                        s[i]='1';
                    }
                   else{ 
                    s[i]='1';
                    cnt++;
                   
                   } i--;
                }
                i++;
            }
        }
        int ans = 0;
        for(char c:s){
            // cout<<c;
            if(c!='0') ans++;
        }
        // cout<<endl;
        return ans ;
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.solve(s, K) << "\n";
    }
}  // } Driver Code Ends
