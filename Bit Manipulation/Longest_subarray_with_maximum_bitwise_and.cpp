class Solution {
public:
  
  //Reminder : Bitwise and of two numbers is always less than or equal to max of them 
  //i.e. (a&b) <= max(a,b) Most important Rule Never Forget it
    int longestSubarray(vector<int>& arr) {
       int len= 0;
      int mk = -1;
        for(int i =0 ; i< arr.size() ;++i){
            
            mk = max(mk,arr[i]);
            
        }
        // cout<<mk<<endl;
       for(int i = 0; i< arr.size() ;++i){
           if(mk==arr[i]){
              int curr = 0;
               while(i<arr.size() && mk==arr[i++]  ){
                    
                    curr++;
                   
               }
                len = max(len,curr);
               
               
           }
       }
        return len;
    }
};
