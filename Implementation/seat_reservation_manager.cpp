class SeatManager {
public:
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int cnt =1 ;

    SeatManager(int n) {
        // minHeap.push(1);
    }
    
    int reserve() {
        if(minHeap.size()==0) return cnt++;
        int num = minHeap.top();
        minHeap.pop();
        // minHeap.push(++num);
        return num;
    }
    
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
