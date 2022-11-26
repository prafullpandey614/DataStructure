 vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        if(!root) return ans ;
        q.push(root);
        while(q.size()){
            vector<int>v;
            int sz = q.size();
            for(int i = 0 ; i < sz ; ++i){
                TreeNode*temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }ans.push_back(v);
        }
        return ans ;
    }
