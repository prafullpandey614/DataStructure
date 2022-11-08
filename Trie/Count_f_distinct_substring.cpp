//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

struct Node{
   
    Node* links[26];
    
    bool isContainKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
};
/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    int cnt = 0 ;
    Node *root = new Node();
    //Your code here
    for(int i = 0 ; i < s.size() ; ++i){
       Node *node = root ;
       for(int j = i ; j <s.size(); ++j){
           if(!node->isContainKey(s[j])){
               node->put(s[j],new Node());
               cnt++;
           }
           node = node->get(s[j]);
       }
    }
    return cnt+1;
    
}
