#include <bits/stdc++.h>
using namespace std ;

#define mxN 100000
long long ar[mxN + 5] ;
long long segtree[mxN * 4] ;

// Building segmentree in O(n)
void Build(int cur, int left, int right) {
    if (left == right) {
        segtree[cur] = ar[left] ;
        return ;
    }
    int mid = (left + right) / 2 ;
    Build(cur * 2 , left , mid) ;
    Build(cur * 2 + 1 , mid + 1, right) ;
    segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1] ;
    return ;
}
// Query the sum in O(logN)
long long Query(int cur, int left, int right, int l, int r) {
    if (l > right || r < left)
        return 0 ; 
    if (left >= l && right <= r)
        return segtree[cur] ;
    int mid = (left + right) / 2 ;
    long long p1 = Query(cur * 2, left, mid, l, r) ;
    long long p2 = Query(cur * 2 + 1 , mid + 1, right, l, r) ;
    return p1 + p2 ;
}
// Updating in O(logN)
void Update(int cur, int left, int right, int pos , long long newvalue) {
    if (pos > right || pos < left)
        return ; 
    if (left >= pos && right <= pos) { 
        segtree[cur] += newvalue ;
        return;
    }
    int mid = (left + right) / 2 ;
    Update(cur * 2 , left, mid, pos, newvalue) ;
    Update(cur * 2 + 1 , mid + 1, right , pos , newvalue) ;
    segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1] ;
    return ;
}
int main() {
    int tc ,test = 0 ;
    scanf("%d",&tc) ;
    
    while(tc--) {
        int n , q ;
        scanf("%d%d",&n,&q) ;
        
        for(int i = 1 ; i <= n ; i++)
            scanf("%lld",&ar[i]) ;
        
        Build(1 , 1 , n) ;
        
        printf("Case %d:\n" , ++test) ;
        
        while(q--) {
            
            int x ;
            scanf("%d",&x) ;
            
            if(x == 1) {
                
                int pos ;
                scanf("%d",&pos) ; 
                pos++ ;
                printf("%lld\n",ar[pos]) ;

                Update(1 , 1 , n , pos , -ar[pos]) ;
                
                ar[pos] = 0 ;
            } else if(x == 2) {
                int pos ;
                long long val ;
                scanf("%d%lld",&pos , &val) ;
                pos++ ;

                Update(1 , 1 , n , pos , val) ;
                
                ar[pos] += val ;
            } else if(x == 3) {
                int l , r ;
                scanf("%d%d",&l ,&r) ;
                l++ , r++ ;
                
                long long ans = Query(1 , 1 , n  , l , r) ;
                
                printf("%lld\n" ,ans) ;
            }
        }
    }
    return 0;
}
