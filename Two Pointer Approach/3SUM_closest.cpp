class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
       sort(v.begin(),v.end());
        int ans  = 0;
        int curr = 0;
        int diff= INT_MAX;
        //revised
        for(int i = 0; i< v.size()-2;++i){
            int j =  i+1 ; int k  = v.size()-1;
            while(j<k){
                curr = v[i]+v[j]+v[k];
                if(diff>abs(curr-target)){
                    ans= curr;
                    diff = abs(curr-target) ;
                }
                diff = min(diff,abs(target-curr));
                if(curr==target) return curr;
                if(curr>target){
                    k--;
                    
                }
                else j++;
            }
        }
        return ans;
    }
};
