class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        int m = potions.size();
        bool f = 0;
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<n;++i){
            int temp = spells[i];
            auto count=lower_bound(potions.begin(),potions.end(),(success+temp-1)/temp);
            ans.push_back(m-(count-potions.begin()));
           
                
            }
           
            
            
        
        return ans;
    }
};
