class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> g  ;
        int m = nums.size()-k+1;
        for(int x:nums){
            g.push(x);
            if(g.size()>m){
                g.pop();
            }
        }
        return g.top();
    }
};
