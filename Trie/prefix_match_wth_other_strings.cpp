//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
   struct Node{
        int pre_cnt;
        unordered_map<char,Node*>next;
        Node(){
            pre_cnt=0;
        }
    };
    int klengthpref(string a[], int n, int k, string s){    
        if(s.length()<k)return 0;
        Node* root = new Node();
        int i,j,cnt=0;
        for(i=0;i<n;i++){
            string x=a[i];
            Node *temp=root;
            for(j=0;j<x.length();j++){
                if(temp->next.find(x[j])==temp->next.end())temp->next[x[j]]=new Node();
                temp=temp->next[x[j]];
                temp->pre_cnt++;
            }
        }
        Node *temp=root;
        for(i=0;i<k;i++){
            if(temp->next.find(s[i])==temp->next.end())return 0;
            else temp=temp->next[s[i]];
        }
        return temp->pre_cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
