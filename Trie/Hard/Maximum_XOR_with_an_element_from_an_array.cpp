struct Node{
    Node*links[2];
    
    bool isContainsKey(int bit){
        return links[bit]!=NULL;
    }
    
    void put(int bit,Node*node){
        links[bit] = node ;
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
        Node*node= root;
        for(int i=31 ; i>=0 ; --i)
        {
            int bit =((num>>i)&1);
            if(!node->isContainsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    
    int findMax(int num){
        Node*node =root ;
        int ans = 0;
        for(int i=31;i>=0;--i)
        {
            int bit = ((num>>i)&1);
            if(node->isContainsKey(1-bit)){
                ans =(ans | (1<<i));
                node= node->get(1-bit);
            }
            else
            node = node->get(bit);
            
        }
        return ans;
    }
    
    
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>offlineQueries;
        int ind = 0;
        for(auto x:queries){
            offlineQueries.push_back({x[1],{x[0],ind++}});
        }
        sort(offlineQueries.begin(),offlineQueries.end());
        ind=  0;
        Trie* trie = new Trie() ;
        vector<int>ans(queries.size());
        for(auto x:offlineQueries){
            int mi = x.first;
            int xi = x.second.first;
            int id = x.second.second ;
            while(ind<nums.size() && nums[ind]<=mi)
            {
                trie->insert(nums[ind]);
                ind++;
            }
            if(ind!=0)
            ans[id] = trie->findMax(xi);
            else ans[id] =-1;
            
        }
        return ans;
    }
};
