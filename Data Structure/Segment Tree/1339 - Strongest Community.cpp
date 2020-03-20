#include <bits/stdc++.h>
using namespace std ;

#define INF9 1e9
#define mxN 100000
int ar[mxN + 10] ;
pair<int , int> seg[mxN << 2] ;
int dp[mxN + 10] ;

pair<int ,int> Getmax(pair<int, int> a , pair<int , int> b) {
    if(a.first > b.first)
        return a ;
    if(a.first < b.first)
        return b ;
    if(a.second >= b.second)
        return a ;
    return b ;
}
void Build(int cur , int left , int right) {
    if(left == right) {
        seg[cur] = make_pair(dp[left] , left) ;
        return ;
    }
    int mid = (left + right) >> 1 ;
    Build((cur << 1) , left , mid) ;
    Build((cur << 1) | 1 , mid + 1 , right) ;
    seg[cur] = Getmax(seg[(cur << 1)] , seg[(cur << 1) | 1]) ;
    return ;
}
pair<int , int> Query(int cur , int left , int right ,int l , int r) {
    if(l > right || r < left)
        return make_pair(-INF9 , 0) ;
    if(left >= l && right <= r) 
        return seg[cur] ;
    int mid = (left + right) >> 1 ;
    return Getmax(Query((cur << 1) , left , mid , l , r) , Query((cur << 1) | 1 , mid + 1 , right , l , r)) ;
}
int main() {
    int tc , test  = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        int n , c , q ;
        scanf("%d%d%d",&n,&c,&q) ;
        dp[0] = 0 ;
        for(int i = 1 ; i <= n ; i++) {
            scanf("%d",&ar[i]) ;
            dp[i] = 1 ;
        }
        for(int i = 1 ; i <= n ; i++) {
            while(i <= n && ar[i] == ar[i - 1]) {
                dp[i] = dp[i - 1] + 1  ;
                i++ ;
            }
        }
        Build(1 , 1 , n) ;
        printf("Case %d:\n", ++test) ;
        while(q--) {
            int l , r ;
            scanf("%d%d",&l,&r) ;
            pair<int , int> now = Query(1 , 1 , n , l , r) ;
            int ans = now.first ;
            if(ar[now.second] == ar[ l - 1]) {
                ans = now.second - (l - 1) ;
                if(now.second < r) {
                    now = Query(1 , 1 , n , now.second + 1 , r) ;
                    ans = max(ans , now.first) ;
                }
            }
            printf("%d\n", ans) ;
        }
    }
    return 0 ;
}
