class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int c:arr) mp[c]++;
        for(auto x:mp) if(x.second>=(arr.size()+3)/4) return x.first;
        return arr[0]; //non sense
        
    }
};
