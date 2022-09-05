/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>>ans;
        if(root==NULL) return {};
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
               vector<int>temp ;
            for(int i = 0 ; i < sz ; ++i){
                Node* current = q.front();
                q.pop();
                for(auto child: current->children){
                    q.push(child);
                }
                temp.push_back(current->val);
                
            }
            ans.push_back(temp);
            
        }
        return ans ;
        
        
    }
};
