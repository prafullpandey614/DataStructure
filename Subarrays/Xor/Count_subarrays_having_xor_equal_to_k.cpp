int Solution::solve(vector<int> &A, int B) {
    int count = 0 ;
    int prefix_xor = 0 ;
    map<int,int>mp;
    for(int i = 0 ;i <A.size(); ++i){
        //logic we have to find no. of subarrays having xor Y = prefix_xor^B
        prefix_xor  = prefix_xor^A[i];
        if(prefix_xor==B) count++;
        count += mp[prefix_xor^B]; //checking in mp for all values of Y
        mp[prefix_xor]++;
    }
    return count ;
}
