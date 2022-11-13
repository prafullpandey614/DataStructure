https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void putEnd(int temp ,stack<int>&s){
    if(s.empty()){
        s.push(temp);
        return  ;
    }
    
    int rem = s.top();
    s.pop();
    putEnd(temp,s);
    s.push(rem);
    return ;
    
}
    void rev(stack<int>&s){
        //base
        if(s.empty()) return ;
        //hypothesis
         int temp = s.top();
         s.pop();
         rev(s);
        //induction
        putEnd(temp,s);
    }
    void Reverse(stack<int> &St){
        rev(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends
