//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
   bool count(vector<int> &arr,int target,int mid){
        int cnt=0; // count number of pieces possible having atleast mid sweetness
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>=mid){
                // one piece over update counter and set sum = 0 to count sweetness of next chunk
                cnt++;
                sum=0;
            }
        }
        if(cnt<target){
            return false;
        }
        return true;
    } 
    int maxSweetness(vector<int>& arr, int n, int k) {
        // Write your code here.
        int low = *min_element(arr.begin(),arr.end());
        int high = 0;
        for(auto x:arr){
            high+=x;
        }
        while(low<=high){
            int mid = low + (high - low)/2;
            if(count(arr,k+1,mid)==false){
                // if number of pieces we can make having min sweetness mid is less than k+1 then go left 
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return high;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends
