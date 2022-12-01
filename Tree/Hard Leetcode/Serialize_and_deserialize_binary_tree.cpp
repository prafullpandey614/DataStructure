/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // vector<int>level ;
        if(!root) return "";
        string ans ="";
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            for(int i = 0; i < sz ;++i){
                auto g= q.front();
                q.pop();
                if(!g){
                    ans.push_back('$');
                    ans.push_back(',');
                    continue ;
                }
                
                ans+= to_string(g->val)+',';
                
                if(g) q.push(g->left);
                // else ans.push_back('$');
                if(g) q.push(g->right);
                // else ans.push_back('$');
                
            }
            
        }
        cout<<ans;
        return ans ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        queue<TreeNode*>q;
        TreeNode*root ;
        // q.push_back()
         stringstream s(data);
        string str; 
        getline(s, str, ',');
        root = new TreeNode(stoi(str)) ;
        q.push(root);
        while(q.size()){
           auto x = q.front();
            q.pop();
           getline(s, str, ',');
            if(str=="$"){
                x->left=NULL;
            }
            else{
                x->left = new TreeNode(stoi(str));
                q.push(x->left);
            }
            // x = q.front();q.pop();/
            getline(s, str, ',');
            if(str=="$"){
                x->right = NULL ;
            }
            else {
                x->right = new TreeNode(stoi(str));
                q.push(x->right);
            }
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
