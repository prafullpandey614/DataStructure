#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<vector<int>> &arr, int idx) {
    int l = 0, r = idx-1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(arr[mid][1] <= arr[idx][0]) {
            if(arr[mid+1][1] <= arr[idx][0]) {
                l = mid+1;
            }
            else {
                return mid;
            }
        }
        else {
            r = mid-1;
        }
    }
    return -1;
}

int maxProfit(vector<vector<int>> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 0);
    dp[0] = arr[0][2];
    for(int i=1; i<n; i++) {
        int profit = arr[i][2];
        int last = binarySearch(arr, i);
        if(last != -1) {
            profit += dp[last];
        }
        dp[i] = max(dp[i-1], profit);
    }
    return dp[n-1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i=0; i<n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    cout << maxProfit(arr) << endl;
    return 0;
}
