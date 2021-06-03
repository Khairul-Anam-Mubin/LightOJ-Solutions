#include <bits/stdc++.h>
using namespace std ;

int ar[101] ;
int tmp[101] ;

int main() {
    int tc , test = 0 ;
    cin >> tc ;
    while(tc--) {
        int n  ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++) {
            cin >> ar[i] ;
            tmp[i] = ar[i] ;
        }
        sort(tmp , tmp + n) ;
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++) {
            if(ar[i] != tmp[i]) {
                int j ;
                for(j = i ; j < n ; j++) {
                    if(ar[j] == tmp[i]) 
                        break ;
                }
                swap(ar[i] , ar[j]) ;
                cnt++ ;
            } 
        }
        cout << "Case " << ++test << ": " << cnt << "\n" ;
    }

    return 0 ;
}
