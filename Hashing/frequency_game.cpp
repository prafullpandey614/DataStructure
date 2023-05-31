unordered_map<int,int>mm;
        for(int i=0;i<n;i++){
            mm[arr[i]]++;
        }
        
        int f=INT_MAX;
        int ans=0;
        
        
        for(auto x:mm){
            if(x.second<f){
                ans=x.first;
                f=x.second;
            }
            else if(x.second==f){
                ans=max(ans,x.first);
            }
            
        }
        return ans;

