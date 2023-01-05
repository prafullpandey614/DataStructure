//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#include <bits/stdc++.h> 

struct Node{
  
    Node*links[26];
    bool isEnd = false ;
    
    bool isContainKey(char ch){
      return (links[ch-'a']!=NULL);
        
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,Node* node){
        links[ch-'a'] = node ;
    }
    void setEnd(){
        isEnd = true ;
    }
};

class Trie{
    private  : Node *root ;
    public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
    Node* node = root ;
    for(int i = 0; i  <word.size() ;++i){
        if(!node->isContainKey(word[i])){
            node->put(word[i],new Node());
        }
        node = node->get(word[i]);
    }
    node->setEnd();
    }
    
    bool allPrefExist(string s){
        Node*node = root ;
        bool flag = true ;
        for(int i = 0 ;i < s.size() ;++i){
         if(node->isContainKey(s[i])){
             node = node->get(s[i]);
             flag = flag & node->isEnd ;
         }
            else return false;
        }
        return flag;
    }
};


class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        Trie*obj = new Trie();
        for(auto x:words) obj->insert(x);
        string longest= "";
        for(int i = 0 ; i < words.size(); ++i){
            if(obj->allPrefExist(words[i])){
                if(words[i].length()>longest.length()) longest = words[i];
                else if(words[i].length()==longest.length()) longest=  min(longest,words[i]);
            }
        }
        return longest ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends
