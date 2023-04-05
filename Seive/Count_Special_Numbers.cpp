//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        unordered_map<int,int>mp;
        // for(int x:arr) mp[x]++;
        sort(arr.begin(),arr.end());
        int sz = arr[N-1];
        int abrr[sz+1];
        
        memset(abrr,0,sizeof abrr);
        for(int c:arr){
                if(mp.count(c)){
                    abrr[c]= 1;
                    continue ;
                }
                for(int j = c*2 ;j <= sz ; j+=c ){
                    abrr[j] = 1;
                }
                mp[c]++;
            
            
        }
        int cnt = 0 ;
        for(int i = 0; i < N ; ++i){
           if(mp[arr[i]]>1 or abrr[arr[i]]!=0) cnt++;
        }
       
        return cnt ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
