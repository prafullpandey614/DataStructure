class Solution {
public:
    #define ll long long
    long long countGood(vector<int>& nums, int k) {
        ll ans = 0;
        int n = nums.size();
        unordered_map<ll,ll>mp;
        ll l = 0 ;
        ll res = 0 ;
        ll cnt = 0 ;
        for(int i = 0 ; i < n ; ++i){
            // mp[nums[i]]++;
            while(l<n && cnt<k){
                mp[nums[l]]++;
                if(mp[nums[l]]>1){
                    cnt+=mp[nums[l]]-1;
                }
                l++;
            }
            if(cnt>=k)
            res+= n-l+1;
            cnt-=(mp[nums[i]]-1);
            mp[nums[i]]--;
            
        }
       
        return res ;
    }
};

//second approach
class Solution {
public:
    #define ll long long
    long long countGood(vector<int>& nums, int k) {
        ll ans = 0;
        int n = nums.size();
        unordered_map<ll,ll>mp;
        ll l = 0 ;
        ll res = 0 ;
        ll cnt = 0 ;
        for(int i = 0 ; i < n ; ++i){
            mp[nums[i]]++;
            while(l<n && cnt<k){
                mp[nums[++l]]++;
                if(mp[nums[l]]>1){
                    cnt+=mp[nums[l]]-1;
                }
            }
            int k = n-l+1;
            cnt-=(mp[nums[i]]-1);
            mp[nums[i]]--;
            res+=k*1LL*(k-1)/2;
        }
       
        return res ;
    }
};
