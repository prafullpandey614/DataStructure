class MedianFinder {
public:
    priority_queue<int> pqMax;
    priority_queue<int,vector<int>,greater<int>> pqMin;
    MedianFinder() {
       
    }
    
    void addNum(int num) {
       if(pqMax.size() == pqMin.size())
       {
           if(!pqMin.empty() && pqMin.top() < num)
           {
               int t = pqMin.top();
               pqMin.pop();
               pqMin.push(num);
               pqMax.push(t);
           }
           else{
               pqMax.push(num);
           }
       }
       if(pqMax.size()  > pqMin.size())
       {
           if(pqMax.top() < num)
           {
               pqMin.push(num);
           }
           else{
               int t = pqMax.top();
               pqMax.pop();
               pqMax.push(num);
               pqMin.push(t);
           }
       }   
    }
    
    double findMedian() {
        if(pqMin.size() != pqMax.size())
        {
            return double(pqMax.top());
        }
        else{
            return (pqMin.top() + pqMax.top())/(double)2;
        }
    }
};
