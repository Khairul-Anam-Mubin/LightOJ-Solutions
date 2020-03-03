#include <bits/stdc++.h>
using namespace std ;
 
#define mxN 100000
 
struct node {
    int zero , one , two , prop ;
} ;
node segtree[mxN * 4] ;
 
void Build(int cur ,int left , int right) {
    if(left == right) {
        segtree[cur].zero = 1 ;
        return ;
    }
    int mid = (left + right) / 2 ;
    Build(cur * 2 , left , mid) ;
    Build(cur * 2 + 1 , mid + 1 , right ) ;
    segtree[cur].zero = segtree[cur * 2].zero + segtree[cur * 2 + 1].zero ;
    return ;
}
void Update(int cur , int left , int right , int l , int r) {
    if(segtree[cur].prop % 3 == 1) {
        int tmp = segtree[cur].zero ;
        segtree[cur].zero = segtree[cur].two ;
        segtree[cur].two = segtree[cur].one ;
        segtree[cur].one = tmp ;
        if(left != right) {
            segtree[cur * 2].prop += segtree[cur].prop ;
            segtree[cur * 2 + 1].prop += segtree[cur].prop ;
        }
        segtree[cur].prop = 0 ;    
       
    } else if(segtree[cur].prop % 3 == 2) {
        int tmp = segtree[cur].zero ;
        segtree[cur].zero = segtree[cur].one ;
        segtree[cur].one = segtree[cur].two ;
        segtree[cur].two = tmp ;
         if(left != right) {
            segtree[cur * 2].prop += segtree[cur].prop ;
            segtree[cur * 2 + 1].prop += segtree[cur].prop ;    
        }
        segtree[cur].prop = 0 ;    
    }
    if(l > right || r < left)
        return ;
    if(left >= l && right <= r) {
        int tmp = segtree[cur].zero ;
        segtree[cur].zero = segtree[cur].two ;
        segtree[cur].two = segtree[cur].one ;
        segtree[cur].one = tmp ;
        if(left != right) {
            segtree[cur * 2].prop++ ;
            segtree[cur * 2 + 1].prop++ ;
        }
        return ;
    }
    int mid = (left + right) / 2 ;
    Update(cur * 2 , left , mid , l , r) ;
    Update(cur * 2 + 1 , mid + 1, right ,l , r) ;
    segtree[cur].zero = segtree[cur * 2 ].zero + segtree[cur * 2 + 1].zero ;
    segtree[cur].one = segtree[cur * 2 ].one + segtree[cur * 2 + 1].one ;
    segtree[cur].two = segtree[cur * 2 ].two + segtree[cur * 2 + 1].two ;
    return ;
}
int Query(int cur , int left , int right ,int l , int r) {
    if(l > right || r < left)
        return 0 ;
    if(segtree[cur].prop % 3 == 1) {
        int tmp = segtree[cur].zero ;
        segtree[cur].zero = segtree[cur].two ;
        segtree[cur].two = segtree[cur].one ;
        segtree[cur].one = tmp ;
        if(left != right) {
            segtree[cur * 2].prop += segtree[cur].prop ;
            segtree[cur * 2 + 1].prop += segtree[cur].prop ;    
        }
        segtree[cur].prop = 0 ;    
    } else if(segtree[cur].prop % 3 == 2) {
        int tmp = segtree[cur].zero ;
        segtree[cur].zero = segtree[cur].one ;
        segtree[cur].one = segtree[cur].two ;
        segtree[cur].two = tmp ;
        if(left != right) {
            segtree[cur * 2].prop += segtree[cur].prop ;
            segtree[cur * 2 + 1].prop += segtree[cur].prop ;    
        }
        segtree[cur].prop = 0 ;    
    }
    if(left >= l && right <= r) {
        return segtree[cur].zero ;
    }
    int mid = (left + right) / 2 ;
    int p1 = Query(cur * 2 , left , mid , l , r) ;
    int p2 = Query(cur * 2 + 1 , mid + 1 , right , l , r) ;
    return (p1 + p2) ;
}
int main() {
    int tc , test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        int n , q ;
        scanf("%d%d",&n,&q) ;
        memset(segtree , 0 , sizeof(segtree)) ;
        Build(1 , 0 , n - 1) ;
        printf("Case %d:\n", ++test);
        while(q--) {
            int x , l , r ;
            scanf("%d%d%d",&x,&l,&r) ;
            if(l > r)
                swap(l , r) ;
            if(x == 0) {
                Update(1 , 0 , n - 1 , l , r) ;
            } else if(x == 1) {
                int ans = Query(1 , 0 , n - 1 , l , r) ;
                printf("%d\n", ans);
            }
        }
    }
    return 0 ;
}
