/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node*node,unordered_map<int,Node*>&mp){
        if(!node) return node ;
        if(mp.find(node->val)!=mp.end()){
            return  mp[node->val];
        }

        Node*kn = new Node(node->val);
        mp[node->val] = kn;
        for(auto x:node->neighbors){
            kn->neighbors.push_back(dfs(x,mp));
        }
        return kn;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*>mp;
        return dfs(node,mp);
    }
};
