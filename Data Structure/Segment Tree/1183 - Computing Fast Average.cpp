#include <bits/stdc++.h>
using namespace std ;

template <typename T> T gcd(T a,T b){
    if(a < 0)return gcd(-a,b);
    if(b < 0)return gcd(a,-b);
    return (b == 0)?a:gcd(b,a%b);
}
#define mxN 100000
long long segtree[mxN * 4] ;
long long lazy[mxN * 4] ;

void Update(int cur , int left , int right , int l , int r , long long val) {
    if(lazy[cur] != -1) {
        segtree[cur] =  (right - left + 1) * lazy[cur] ;
        if(left != right) {
            lazy[cur * 2] = lazy[cur] ;
            lazy[cur * 2 + 1] = lazy[cur] ;
        }
        lazy[cur] = -1 ;
    }
    if(l > right || r < left) 
        return ;
    if(left >= l && right <= r) {
        segtree[cur] = (right - left + 1) * val ;
        if(left != right) {
            lazy[cur * 2] = val ;
            lazy[cur * 2 + 1] = val ;
        }
        return ;
    }
    int mid = (left + right) / 2 ;
    Update(cur * 2 , left , mid , l , r , val) ;
    Update(cur * 2 + 1 , mid + 1 , right , l , r , val) ;
    segtree[cur] = segtree[cur * 2 ] + segtree[cur * 2 + 1] ;
    return ;
}
long long Query(int cur , int left , int right , int l , int r) {
    if(l > right || r < left) 
        return 0 ;
    if(lazy[cur] != -1) {
        segtree[cur] = (right - left + 1) * lazy[cur] ;
        if(left != right) {
            lazy[cur * 2] = lazy[cur] ;
            lazy[cur * 2 + 1] = lazy[cur] ;
        }
        lazy[cur] = -1 ;
    }
    if(left >= l && right <= r)
        return segtree[cur] ;
    int mid = (left + right) / 2 ;
    long long p1 = Query(cur * 2 , left , mid , l  , r) ;
    long long p2 = Query(cur * 2 + 1 , mid + 1 , right , l , r ) ;
    return (p1 + p2) ;
}
int main() {
    int tc , test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        int n , q ;
        scanf("%d%d",&n,&q) ;
        memset(segtree , 0 , sizeof(segtree)) ;
        memset(lazy , -1 , sizeof(lazy)) ;
        printf("Case %d:\n",++test );
        while(q--) {
            int x ; 
            scanf("%d",&x) ;
            if(x == 1) {
                int l , r ;
                long long val ;
                scanf("%d%d%lld",&l,&r,&val) ;
                Update(1 , 0 , n - 1 , l , r , val) ;
            } else if(x == 2) {
                int l , r ;
                scanf("%d%d",&l,&r) ;
                long long sum = Query(1 , 0 , n - 1, l , r) ;
                long long num = r - l + 1 ; 
                long long g = gcd(sum , num) ;
                sum /= g ;
                num /= g ;
                if(num == 1) {
                    printf("%lld\n",sum);
                } else if(num == 0) {
                    printf("0\n");
                } else {
                    printf("%lld/%lld\n", sum , num);
                }
            }
        }
    }

    return 0 ;
}
