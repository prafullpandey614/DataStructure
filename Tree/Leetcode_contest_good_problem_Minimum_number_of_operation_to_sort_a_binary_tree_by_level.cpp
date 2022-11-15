class Solution {
public:
   int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int minii = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> arr(size);
            int i=0;
            while(size--){
                TreeNode* n = q.front();
                q.pop();
                arr[i++] = n->val;
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
            minii+=minSwaps(arr);
        } 
        return minii;
    }
    int minSwaps(vector<int>&arr){
        int ans = 0; 
        
        unordered_map<int,int>mp;
        for(int i = 0 ; i < arr.size() ; ++i){
            mp[arr[i]] = i;
        }
        sort(arr.begin(),arr.end());
        for(int i =0 ; i < arr.size() ; ++i){
            if(mp[arr[i]]==i) continue;
            while(mp[arr[i]]!=i && i<arr.size()){
                ans++;
                swap(arr[i],arr[mp[arr[i]]]);
                
            }
        }
        return ans ;
    }
