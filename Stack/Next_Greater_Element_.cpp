vector<long long> nextLargerElement(vector<long long> &arr, int n){
       vector<long long>ans;
       stack<int>st;
       for(int i = 0 ; i <  n ; ++i){
           if(st.empty()){
               st.push(arr[i]);
           }
           else{
               while(!st.empty() && st.top()<arr[i]){
                   ans.push_back(arr[i]);
                   st.pop();
               }
               st.push(arr[i]);
               
           }
       }
       while(!st.empty()){
           ans.push_back(-1);
           st.pop();
       }
       return ans;
    }
