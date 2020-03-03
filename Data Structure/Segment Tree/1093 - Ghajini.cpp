#include <bits/stdc++.h>

using namespace std ;

#define INF9 2147483647
#define mxN 100000
long long ar[mxN + 10] ;

struct node{
    long long mx , mn ;
} ;
node segtree[mxN * 4] ;

void Build(int cur , int left , int right) {
    if(left == right) {
        segtree[cur].mx = ar[left] ;
        segtree[cur].mn = ar[left] ;
        return ;
    }
    int mid = (left + right) / 2 ;
    Build(cur * 2 , left , mid ) ;
    Build(cur * 2 + 1 ,mid + 1 , right) ;
    segtree[cur].mx = max(segtree[cur * 2].mx , segtree[cur * 2 + 1].mx) ;
    segtree[cur].mn = min(segtree[cur * 2].mn , segtree[cur * 2 + 1].mn) ;
    return ;
} 
node Query(int cur , int left , int right ,int l , int r) {
    if(l > right || r < left) {
        node ok ;
        ok.mx = -INF9 ;
        ok.mn = INF9 ;
        return ok ;
    }
    if(left >= l && right <= r) {
        return segtree[cur] ;
    }
    int mid = (left + right) / 2 ;
    node c1 = Query(cur * 2 , left , mid , l , r) ;
    node c2 = Query(cur * 2 + 1 , mid + 1 , right , l , r) ;
    node f ;
    f.mx = max(c1.mx , c2.mx) ;
    f.mn = min(c1.mn , c2.mn) ;
    return f ;
}
int main() {
    int tc ,test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        int n , d ;
        scanf("%d%d",&n,&d) ;
        for(int i = 0 ; i < n ; i++) {
            scanf("%lld",&ar[i]) ;
        }
        memset(segtree , 0 , sizeof(segtree)) ;
        Build(1 , 0 , n - 1) ;
        long long ans = 0 ;
        for(int i = 0 ; i < n - d + 1 ; i++) {
            node ok = Query(1 , 0 , n - 1 , i , i + d - 1) ;
            ans = max(ans , ok.mx - ok.mn) ;
        }
        printf("Case %d: ",++test) ;
        printf("%lld\n",ans) ;
    }
    return 0 ;
}
