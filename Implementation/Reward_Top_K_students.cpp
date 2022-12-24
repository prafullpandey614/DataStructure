class Solution {
public:
  static  bool cmp(pair<int,int>&p1,pair<int,int>&p2){
         if(p1.second!=p2.second){
            return (p1.second > p2.second);
           }
   
            return p1.first<p2.first;
        
    }
    vector<int> topStudents(vector<string>& post, vector<string>& negt, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,int>pos;
        unordered_map<string,int>neg;
        unordered_map<int,int>kans;
        vector<string>v1,v2;
        for(auto x:post) pos[x]++;
        for(auto x:negt) neg[x]++;
        vector<pair<int,int>>v;
        int i = -1;
        for(auto s:report){
            i++;
            string curr="";
            int score= 0 ;
            for(char i:s){
                
                if(i==' ') {
                    
                    if(pos.find(curr)!=pos.end()){
                        score+=3;
                        
                    }
                    else if(neg.find(curr)!=neg.end()){
                        score-=1;
                    }
                    curr="";
                }
                else curr.push_back(i);
            }
            if(curr!=""){
                 if(pos.find(curr)!=pos.end()){
                        score+=3;
                        
                    }
                    else if(neg.find(curr)!=neg.end()){
                        score-=1;
                    }
                    curr="";
            }
            v.push_back({student_id[i],score});
           
        }
 

        vector<pair<int,int>>bans;
        for(auto x:kans){
            bans.push_back({x.second,x.first});
        }
        vector<int>ans ;
        int m = 0;
        sort(v.begin(),v.end(),cmp);
        m= 0 ;
        for(auto x:v){
            if(m==k) break;
            ans.push_back(x.first);
            m++;
        }
        
        return ans;
    }
};
