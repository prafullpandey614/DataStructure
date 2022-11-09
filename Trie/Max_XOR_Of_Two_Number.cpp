

struct Node{
    Node*links[2];
    bool isContainsKey(int bit){
        return links[bit]!=NULL;
    }
    
    void put(int bit,Node*node){
        links[bit]= node;
    }
    Node*get(int bit){
        return links[bit];
    }
    
};
class Trie{
    public:
    Node*root ;
    Trie(){
        root = new Node();
    }
    
  
    void insert(int num){
        Node*node = root;
        for(int i =31 ;i>=0 ;--i){
            int bit = ((num>>i)&1) ;
            if(!node->isContainsKey(bit)){
                node->put(bit,new Node());
                
            }
            node= node->get(bit);
        }
    }
    
    int findMax(int num){
        int ans_max=0;
        Node*node=  root;
        for(int i=31; i>=0 ; --i){
            int bit =((num>>i)&1);
            if(node->isContainsKey(1-bit)){
                ans_max =( ans_max | (1<<i));
                 node = node->get(1-bit);
            }
           else  node = node->get(bit);
        }
        return ans_max;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie*trie = new Trie() ;
        for(auto &x:nums) trie->insert(x);
        int ans=  0;
        for(int x:nums){
            ans = max(ans,trie->findMax(x));
        }
        return ans;
    }
};
