#include<bits/stdc++.h>
using namespace std;

string solve (int n, vector<int> arr) {
   // Write your code here
   unordered_map<int,int>mp;
   for(int x:arr) mp[x]++;
   priority_queue<int>pq;
   for(auto x:mp){
      for(int i = 1 ; i <= x.second ;++i){
        if(i>2) break;
        pq.push(x.first);
      }
   }
   int i = 0 ;
   int sum1 =0 ,sum2 =0 ; 
   while(pq.size()>0){
     if(i&1) sum2+=pq.top();
     else sum1+=pq.top();
     pq.pop();
     i++;
   }
   if(sum2>=sum1) return "Bob";
   else return "Alex";
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i_arr = 0; i_arr < n; i_arr++)
        {
        	cin >> arr[i_arr];
        }

        string out_;
        out_ = solve(n, arr);
        cout << out_;
        cout << "\n";
    }
}
