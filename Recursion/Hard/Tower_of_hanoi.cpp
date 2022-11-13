//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int count = 0;
//avoid space at the starting of the string in "move disk....."
int tob(int N,int from,int to ,int mid ){
    count++;
    if(N==1){
        cout<<"move disk 1 from rod "<<from<<" to rod "<<to<<endl;
        
        return count; ;
    }
    else{
        tob(N-1,from,mid,to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        tob(N-1,mid,to,from);
        // cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        
        
    }return count ;
}
long long toh(int N, int from, int to, int aux) {
     count = 0 ;
    
    return tob(N,from,to,aux);
    //  count;
    //Your code here
}

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends
