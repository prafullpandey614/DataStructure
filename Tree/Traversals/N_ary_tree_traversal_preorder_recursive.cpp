 void dfs(Node*root,vector<int>&ans){
        if(root==NULL) return ;
        
        ans.push_back(root->val);
        for(auto x:root->children){
            dfs(x,ans);
        }
        
    }
    vector<int> preorder(Node* root) {
        vector<int>ans;
        dfs(root,ans);
        return ans ;
    }
