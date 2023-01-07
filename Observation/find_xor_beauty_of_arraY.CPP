class Solution {
public:
    int xorBeauty(vector<int>& nums) {
         long long result = 0;
        
        for(int x:nums)
            result ^= x;
        
        return result;
    }
};
