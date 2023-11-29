#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n, const vector<bool>& primes) {
    return primes[n];
}

void sieveOfEratosthenes(int limit, vector<bool>& primes) {
    primes.resize(limit + 1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= limit; ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= limit; j += i) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    const int limit = 1000010;
    vector<bool> primes;

    // Generate primes using Sieve of Eratosthenes
    sieveOfEratosthenes(limit, primes);

    

    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        int k = 1 ;
        bool flag =0 ;
        int attack = 0 ;
        while(h>0){
            
            if(primes[h]){
                attack++;
                h=0;
                // cout<<attack++<<endl;
                
                flag  = 1 ;
                break ;
            }
            h-=k;
            attack++;
            k+=k;
            // if(h<0) break;
        }
        if(h==0) cout<<attack<<endl;
        else{
            cout<<-1<<endl;
        }
    }

    return 0;
}
