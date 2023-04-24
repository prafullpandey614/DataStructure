class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {     int n=arr.size();
        stack<int> stb,stf;
        vector<int> v1(n,1e7),v2(n,1e7);
       
        for(int i=0;i<n;i++){
            while(!stb.empty()&&arr[stb.top()]>=arr[i])
            stb.pop();
            if(!stb.empty())
            v1[i]=stb.top();
            stb.push(i);
        }
        
        for(int i=n-1;i>=0;i--){
            while(!stf.empty()&&arr[stf.top()]>=arr[i])
            stf.pop();
            if(!stf.empty())
            v2[i]=stf.top();
            stf.push(i);
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(v1[i]==1e7&&v2[i]==1e7)
            ans.push_back(-1);
            else if(i-v1[i]!=v2[i]-i){
              if(v1[i]!=1e7&&i-v1[i]<v2[i]-i)
              ans.push_back(v1[i]);
              else
              ans.push_back(v2[i]);
            }
            else{
                if(arr[v1[i]]<arr[v2[i]])
                    ans.push_back(v1[i]);
                   
                else if(arr[v1[i]]>arr[v2[i]])
                ans.push_back(v2[i]);
                else
                ans.push_back(min(v1[i],v2[i]));
            }
        }
        return ans;
    }
};
