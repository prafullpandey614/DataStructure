
//This is brute force solution which won't work for leetcode
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string,int>mp;
        int count = 0;
        for(string s:ideas) mp[s]++;
        int n = ideas.size();
        for(int  i = 0 ; i < n ;++i){
            for(int j = i+1 ; j<n ; ++j){
                string first = ideas[i];
                string second = ideas[j];
                char c  = first[0];
                first[0] = second[0];
                second[0] = c;
                if(mp.find(first)==mp.end() && mp.find(second)==mp.end()){
                    count+=2;
                }
            }
        }
        return count ;
    }
};
