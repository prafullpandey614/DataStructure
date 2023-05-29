//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool matchPattern(string& word, string& patternToMatch) {
        string patternInWord = "";
        
        for(char c: word) {
            if( isupper(c) )
                patternInWord.push_back(c);
                
            if(patternInWord == patternToMatch) 
                return true;
        } 
        
        return false;
    }
    
    vector<string> CamelCase(int n, vector<string> dictionary, string pattern) {
        vector<string> ans;
        
        for(string word: dictionary) {
            
            if( matchPattern(word, pattern) )
                ans.push_back(word);
                
        }
        
        // edge case
        if( ans.empty() ) 
            return {"-1"};

        sort(begin(ans), end(ans));
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
