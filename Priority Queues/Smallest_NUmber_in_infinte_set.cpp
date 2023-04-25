class SmallestInfiniteSet {
private:
priority_queue<int>pq;vector<int>v;

// unordered_map<int,int>mp;

public:
    SmallestInfiniteSet() {
        for(int i = 1; i<=1000 ; ++i) pq.push(-i);
        v.resize(1e4,1);
    }
    
    int popSmallest() {
        if(!pq.size()) return -1;
        int t = pq.top();
        pq.pop();
        v[-t]=0;
        return -t;
    }
    
    void addBack(int num) {
        if(v[num]>0){
            return ;
        }
        v[num]=1;
        pq.push(-num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
