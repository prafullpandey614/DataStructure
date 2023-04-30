class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long op =0;
        map<int,int>mp;
       for(int i = 0 ; i < nums.size() ; ++i){
           mp[nums[i]] = i ;
       }
        vector<int>v;
        for(auto x:mp){
          
            v.push_back(x.second);
        }
    
        int last=  v[0];
        long long d = 1; //items to be deleted now 
        long long n = nums.size(); //size of current array 
        if(v.size()==1) return op+1;
        for(int i = 1; i<v.size(); ++i){
            if(v[i]<last){
                op+=n ; //if index of the next smallest  element < last smallest element then we need to perform n operations to delete this 
                n-=d; 
                d=1;
                last= v[i];
                if(i==v.size()-1) op++;
            }
            else{
                
                d++;
                last=v[i];
                 if(i==v.size()-1) op+=n ;
            }
        }
        return op ;
        
    }
};
