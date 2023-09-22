You are standing at the top of the skyscrapper in NYC with camera, find the direction you should face to take the photo with most buildings

Input array sorted based on angles
2 inputs -> array with each entry representing 1 building at arr[i] degree
and field of view is given as 30 degree, so output the angle at which you will stand that maximum buildings are covered in 30 degree range

arr = [5, 9, 20, 22, 28, 35, 60, 350, 358, 359, 360]
field of view = 30

output : angle with maximum buildings 
https://leetcode.com/discuss/interview-question/3549864/Google-or-sliding-window/1913505




int main() {
   int n = 11 ;
   vector<int>v = {5, 9, 20, 22, 28, 36, 60, 61, 62,63,64} ;
    int k = 30 ;
    int st =0 ;
    int end =0 ;
    int a,b ;
    int ans = 0 ;
    int count = 0 ;
    while(end<n){
        if(v[end]-v[st]<=k){
            count++;
            end++;
        }
        else{
                if(ans<count){
                    a = st ;
                    b = end-1 ;
                }
                ans = max(ans,count);
                st++;
                count--;
        }
    }
     if(ans<count){
                    a = st ;
                    b = end-1 ;
                }
    ans = max(ans,count);
    cout<<ans<<" "<<v[a]<<" "<<v[b];
}
