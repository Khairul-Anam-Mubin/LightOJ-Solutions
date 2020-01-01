#include <bits/stdc++.h>
using namespace std ;

// complexity : O(nloglogn + klogn)

#define mxN 1000000000000
#define mx 1000000
bool isp[mx + 10] ;
vector <long long> prime ;
void sieve(){
    isp[1] = 1 ;
    for(int i = 4 ; i <= mx ; i += 2)
        isp[i] = true;
    for(int i = 3 ; i * i <= mx ; i += 2)
        if(!isp[i])
            for(int j = i * i ; j <= mx ; j +=(i + i))
                isp[j] = true;
    prime.push_back(2);
    for(int i = 3 ; i <= mx ; i += 2)
        if(!isp[i])
            prime.push_back(i);
}
long long NOD ( long long n ) {
    long long res = 1 ;
    for ( int i = 0 ; i < prime.size() && prime[i] * prime[i] <= n ; i++ ) {
        if ( n % prime[i] == 0LL ) {
            long long p = 0 ; // Counter for power of prime
            while ( n % prime[i] == 0LL ) {
                n /= prime[i];
                p++;
            }
            p++; // Increase it by one at end
            res *= p; // Multiply with answer
        }
    }
    if ( n != 1 ) {
        res *= 2LL ; // Remaining prime has power p^1. So multiply with 2/
    }
    return res ;
}
int main() {
    sieve() ;
    int tc , test = 0 ;
    cin >> tc ;
    while(tc--) {
        long long n ;
        cin >> n ;
        cout << "Case " << ++test << ": " ;
        long long ans = NOD(n) - 1LL ;
        cout << ans << "\n" ;
    }
    return 0 ;
}
