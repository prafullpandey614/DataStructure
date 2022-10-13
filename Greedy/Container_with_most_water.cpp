class Solution {
public:
    int maxArea(vector<int>& h) {
        int area=INT_MIN;
        int i = 0 ;
        int j = h.size()-1;
        int curr ;
        while(i<=j){
            curr= (j-i)*(min(h[j],h[i]));
            area = max(area,curr);
            if(h[j]>h[i]){
                i++;
            }
            else j--;
            
        }
        return area;
    }
};
