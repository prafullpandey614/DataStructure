//problem link

#include<bits/stdc++.h>
using namespace std ;

int digit_sum(int n){
    int sum = 0; 
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum ;
}

int sum(vector<int>&v,int n){
    unordered_map<int,int>mp ; //keys -> sum_of_digits , val -> sum of numbers
    int result = -1 ;
    for(int i = 0; i < n ; ++i){
        int sm = digit_sum(v[i]);
        if(mp.find(sm)!=mp.end()){
            result = max(result,mp[sm]+v[i]);
            mp[sm] = max(mp[sm],v[i]);
        }
        else{
            mp[sm] = v[i];
        }
    }
    return result ;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i <n ; ++i){
        cin>>v[i];
    }
    cout<<sum(v,n)<<endl;
}
