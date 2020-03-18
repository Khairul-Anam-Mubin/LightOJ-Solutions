#include <bits/stdc++.h>
using namespace std;

#define mxN 200010

int segtree[mxN * 4] ;
int lazy[mxN * 4] ;
set <int> st ;

void Propagate(int cur , int left , int right) {
    segtree[cur] = lazy[cur] ;
    if(left != right) {
        lazy[cur * 2] = lazy[cur] ;
        lazy[cur * 2 + 1] = lazy[cur] ;
    }
    lazy[cur] = 0 ;
}
void Update(int cur , int left , int right , int l , int r , int col ) {
    if(lazy[cur] != 0) {
        Propagate(cur , left , right) ;
    }
    if(l > right || r < left)
        return ;
    if(left >= l && right <= r) {
        segtree[cur] = col ;
        if(left != right) {
            lazy[cur * 2] = col ;
            lazy[cur * 2 + 1] = col ;
        }
        return ;
    }
    int mid = (left + right) / 2 ;
    Update(cur * 2 , left , mid , l , r , col) ;
    Update(cur * 2 + 1 , mid + 1 , right , l , r , col) ;
    return ;
}
void Query(int cur , int left , int right) {
    if(lazy[cur] != 0) {
        Propagate(cur , left , right) ;
    }
    if(left == right) {
        st.insert(segtree[cur]) ;
        return ;
    }
    int mid = (left + right) / 2 ;
    Query(cur * 2 , left , mid) ;
    Query(cur * 2 + 1 , mid + 1 , right) ;
}
int main() {
    int tc , test  = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        memset(segtree , 0 , sizeof(segtree)) ;
        memset(lazy , 0 , sizeof(lazy)) ;
        st.clear() ;
        int n ; 
        scanf("%d",&n) ;
        int ok = n * 2 + 10 ;
        for(int i = 0 , col = 1 ; i < n ; i++) {
            int l , r ;
            scanf("%d%d",&l,&r) ;
            Update(1 , 1 , ok , l , r , col++) ;
        }
        Query(1 , 1, ok) ;
        int ans = st.size() ;
        ans = max(0 , ans - 1) ;
        printf("Case %d: %d\n", ++test , ans) ;
    }
    return 0 ;
}
