#include <bits/stdc++.h>
using namespace std ;

vector <long long> vec ;
void divisors(long long n) {
    vec.clear() ;
    for(long long i = 1 ; i * i <= n ; i++) {
        if(n % i == 0) {
            vec.push_back(i) ;
            if(i * i != n)
                vec.push_back(n / i) ;
        }
    } 
}
int main() {
    int tc , test = 0 ;
    cin >> tc ;
    while(tc--) {
        long long l , p ;
        cin >> l >> p ;
        divisors(l - p) ;
        vector <long long> ans ;
        for(int i = 0 ; i < vec.size() ; i++) {
            if(vec[i] > p)
                ans.push_back(vec[i]) ;
        }
        cout << "Case " << ++test << ": " ;
        if(ans.size() == 0) {
            cout << "impossible\n" ;
        } else {
            sort(ans.begin() , ans.end()) ;
            for(int i = 0 ; i < (int)ans.size() ; i++) {
                if(i + 1 == ans.size()) {
                    cout << ans[i] << "\n" ;
                }
                else {
                    cout << ans[i] << " " ;
                }
            }
        }
    }
    return 0 ;
}
