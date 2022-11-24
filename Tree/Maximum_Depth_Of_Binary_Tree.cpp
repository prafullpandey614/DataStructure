int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        if(!root) return 0;
        int level = 0;
        while(q.size()){
            int k = q.size();
            for(int i = 0; i < k;++i){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            level++;
        }
        return level ;
    }
