//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
     bool  isprime[10000]={1};
    void findPrimes(){
        
        memset(isprime,1,sizeof(isprime));
        isprime[1] = 0 ;
        isprime[0] = 0;
        for(int i = 2 ; i<10000 ; ++i){
            if(isprime[i])
            for(int j = i*i ; j<10000; j+=i){
                isprime[j] = 0;
               
            }
        }
        return ;
    }
    
    int shortestPath(int a,int b)
    {   
         if(isprime[0])
         findPrimes();
        
        queue<pair<int,int>>q;
        vector<bool>vis(10001,0);
        q.push({a,0}); //num and level
        while(!q.empty()){
                auto el = q.front(); q.pop();
                int num = el.first ;
                int dist = el.second ; //level
                vis[num] = 1;
                //check if target acheived  
                if(num==b) return dist ;
                for(int i = 0; i<4 ; ++i){
                    for(int d = 0 ; d<=9 ;++d){
                        if(i==0 && d==0) continue ;
                        string s = to_string(num);
                        s[i] = '0'+d ; //ascii
                        int new_num = stoi(s);
                        //check if eligible for pushing into queue 
                        if(isprime[new_num] && !vis[new_num] ){
                            q.push({new_num,dist+1});
                            vis[new_num] = 1;
                        }
                    }
                
            }
            
        }
        // Complete this function using prime vector
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends
