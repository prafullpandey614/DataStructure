class Solution {
public:
    #define pb push_back
    #define vect vector<int>
    vector<int> findOriginalArray(vector<int>& changed) {
         if(changed.size()&1) return {};
        unordered_map<int,int>mp;
        for(int x:changed){
            mp[x]++;
        }
       
        vect ans;
        sort(changed.begin(),changed.end());
        for(int i:changed){
            if(mp[i*2]>=1 && i!=0 && mp[i]>0){
                ans.pb(i);
                mp[i*2]-=1;
                mp[i]-=1;
            }
            else if(i==0 && mp[i]>1){
                ans.pb(i);
                mp[i*2]-=1;
                mp[i]-=1;
            }
        }
        if(ans.size()<changed.size()/2) return {};
        return ans;
    }
};
