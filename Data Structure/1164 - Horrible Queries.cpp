
/* 1 based index */
 
#include <bits/stdc++.h>
using namespace std ;
 
#define mxN 100000
 
long long ar[mxN + 10] ;
long long segtree[mxN * 4] ;
long long lazy[mxN * 4] ;
// simply building tree
void Build(int cur , int left , int right) {
    if(left == right) {
        segtree[cur] = ar[left] ;
        return ;
    }
    int mid = (left + right) / 2 ;
    Build(cur * 2 , left , mid) ;
    Build(cur * 2 + 1 , mid + 1 , right) ;
    segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1] ;
    return ;
}
// Lazy update
void Update(int cur , int left , int right , int l , int r , long long val) {
    if(lazy[cur] != 0) {              // if lazy value is non zero then update
        segtree[cur] += (right - left + 1) * lazy[cur] ;
        if(left != right) {         // if this is not child
            lazy[cur * 2] += lazy[cur] ;  // propagating its childs
            lazy[cur * 2 + 1] += lazy[cur] ;
        }
        lazy[cur] = 0 ;           // cur node eluminate so reset 0
    }
    if (l > right || r < left)
        return ;
    if (left >= l && right <= r) {
        segtree[cur] += (right - left + 1) * val ;
        if(left != right) {
            lazy[cur * 2] += val ;
            lazy[cur * 2 + 1] += val ;
        }
        return ;
    }
    int mid = (left + right) / 2 ;
    Update(cur * 2 , left , mid , l , r , val) ;
    Update(cur * 2 + 1 , mid + 1 , right , l , r , val) ;
    segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1] ;
    return ;
}
long long Query(int cur , int left , int right , int l , int r) {
    if(l > right || r < left)
        return 0 ;
    if(lazy[cur] != 0) {
        segtree[cur] += (right - left + 1) * lazy[cur] ;
        if(left != right) {
            lazy[cur * 2] += lazy[cur] ;
            lazy[cur * 2 + 1] += lazy[cur] ;
        }
        lazy[cur] = 0 ;
    }
    if (left >= l && right <= r)
        return segtree[cur] ;
    int mid = (left + right) / 2 ;
    long long p1 = Query(cur * 2 , left , mid , l , r) ;
    long long p2 = Query(cur * 2 + 1 , mid + 1 , right , l , r) ;
    return (p1 + p2) ;
}
int main() {
    int tc ,test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        long long n , q ;
        scanf("%lld%lld",&n,&q) ;
        for(int i = 0 ; i < 4 * mxN ; i++) {
            lazy[i] = 0 ;
            segtree[i] = 0 ;
            if(i <= mxN)
                ar[i] = 0 ;
        }
        Build(1 , 1 , n) ;
        printf("Case %d:\n",++test) ;
        while(q--) {
            int how ;
            scanf("%d",&how) ;
            if(how == 0) {
                long long l , r , val ;
                scanf("%lld%lld%lld",&l,&r,&val) ;
                l++ , r++ ;
                if(l > r)
                    swap(l , r) ;
                Update(1 , 1 , n , l , r , val) ;
            } else if(how == 1) {
                long long l ,  r ;
                scanf("%lld%lld",&l,&r) ;
                l++ , r++ ;
                if(l > r)
                    swap(l , r) ;
                long long ans = Query(1 , 1 , n , l , r) ;
                printf("%lld\n",ans) ;
            }
        }
    }
 
    return 0 ;
}
