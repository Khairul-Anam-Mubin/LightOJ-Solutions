#include <bits/stdc++.h>
using namespace std ;
 
#define mxN 1000
long long v[mxN + 5] ;

void DivSieve() {
    for(int i = 1 ; i <= mxN ; i++) {
        for(int j = i ; j <= mxN ; j += i) {
            v[j]++ ; // counting number of divisors of j
        }
    }
}
bool cmp(pair<int, int> &a , pair<int , int> &b) {
    if(a.first == b.first) 
        return (a.second > b.second) ;
    else
        return (a.first < b.first) ;
}
int main() {
    DivSieve() ;
    vector <pair <int , int>> vec ;
    for(int i = 1 ; i <= mxN ; i++) {
        vec.push_back(make_pair(v[i] , i)) ;
    }
    sort(vec.begin() , vec.end() , cmp) ;
    int tc , test = 0 ;
    cin >> tc ;
    while(tc--) {
        long long n ;
        cin >> n ;
        cout << "Case " << ++test << ": " ;
        cout << vec[n - 1].second << "\n" ;
    }
    return 0 ;
}
