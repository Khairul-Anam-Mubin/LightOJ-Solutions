/* lazy with propagation */

#include <bits/stdc++.h>
using namespace std ;
 
#define mxN 100000
char str[mxN + 10] ;
int lazy[mxN * 4] ;
int segtree[mxN * 4] ;
 
void Build(int cur , int left , int right) {
    if(left == right) {
        segtree[cur] = str[left] - '0' ;
        lazy[cur] = 0 ;
        return ;
    }
    int mid = (left + right) / 2 ;
    Build(cur * 2 , left , mid ) ;
    Build(cur * 2 + 1 , mid + 1 , right) ;
    segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1];
    lazy[cur] = 0 ;
    return ;
}
void Update(int cur , int left , int right , int l , int r) {
    if(lazy[cur] != 0) {
        segtree[cur] = (right - left + 1) - segtree[cur] ;
        if(left != right) {
            lazy[cur * 2] = !lazy[cur * 2] ;
            lazy[cur * 2 + 1] = !lazy[cur * 2 + 1] ;
        }
        lazy[cur] = 0 ;
    }
    if(l > right || r < left)
        return ;
    if(left >= l && right <= r) {
        segtree[cur] = (right - left + 1) - segtree[cur] ;
        if(left != right) {
            lazy[cur * 2] = !lazy[cur * 2] ;
            lazy[cur * 2 + 1] = !lazy[cur * 2 + 1] ;
        }
        return ;
    }
    int mid = (left + right) / 2 ;
    Update(cur * 2 , left , mid , l , r) ;
    Update(cur * 2 + 1 , mid + 1 , right , l , r) ;
    segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1] ;
    return ;
}
int Query(int cur , int left , int right , int l , int r) {
    if(l > right || r < left)
        return 0 ;
    if(lazy[cur] != 0) {
        segtree[cur] = (right - left + 1) - segtree[cur] ;
        if(left != right) {
            lazy[cur * 2] = !lazy[cur * 2] ;
            lazy[cur * 2 + 1] = !lazy[cur * 2 + 1] ;
        }
        lazy[cur] = 0 ;
    }
    if(left >= l && right <= r)
        return segtree[cur] ;
    int mid = (left + right) / 2 ;
    int p1 = Query(cur * 2 , left , mid , l , r) ;
    int p2 = Query(cur * 2 + 1 , mid + 1 , right , l , r) ;
    return (p1 + p2) ;
}
int main() {
    int tc , test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        scanf("%s",str) ;
        int n = strlen(str) ;
        memset(lazy , 0 , sizeof(lazy)) ;
        memset(segtree , 0 , sizeof(segtree)) ;
        Build(1 , 0 , n - 1) ;
        int q ;
        scanf("%d",&q) ;
        printf("Case %d:\n",++test) ;
        while(q--) {
            char ch ;
            scanf(" %c",&ch) ;
            if(ch == 'I') {
                int l , r ;
                scanf("%d%d" ,&l,&r) ;
                l-- , r-- ;
                Update(1 , 0 , n - 1 , l , r) ;
            } else if(ch == 'Q') {
                int pos ;
                scanf("%d",&pos) ;
                pos-- ;
                int ans = Query(1 , 0 , n - 1 , pos , pos) ;
                printf("%d\n",ans) ;
            }
        }
    }
 
    return 0 ;
}

/* Lazy without propagation */

#include <bits/stdc++.h>
using namespace std ;

#define mxN 100000
char str[mxN + 10] ;
struct {
    int sum , prop ;
} segtree[mxN * 4] ;
 
void Build(int cur , int left , int right) {
    if(left == right) {
        segtree[cur].sum = str[left] - '0' ;
        segtree[cur].prop = 0 ;
        return ;
    }
    int mid = (left + right) / 2 ;
    Build(cur * 2 , left , mid ) ;
    Build(cur * 2 + 1 , mid + 1 , right) ;
    segtree[cur].sum = segtree[cur * 2].sum + segtree[cur * 2 + 1].sum ;
    segtree[cur].prop = 0 ;
    return ;
}
void Update(int cur , int left , int right , int l , int r) {
    if(l > right || r < left)
        return ;
    if(left >= l && right <= r) {
        segtree[cur].sum = (right - left + 1) - segtree[cur].sum ;
        segtree[cur].prop = !segtree[cur].prop ;
        return ;
    }
    int mid = (left + right) / 2 ;
    Update(cur * 2 , left ,mid , l , r) ;
    Update(cur * 2 + 1 , mid + 1 , right , l , r) ;
    segtree[cur].sum = segtree[cur * 2].sum + segtree[cur * 2 + 1].sum + (right - left + 1) * segtree[cur].prop ;
    return ;    
}
int Query(int cur , int left , int right , int l ,int r ,int carry = 0) {
    if(l > right || r < left)
        return 0 ;
    if(left >= l && right <= r) {
        return segtree[cur].sum + carry * (right - left + 1) ;
    }
    int mid = (left + right) / 2 ;
    int p1 = Query(cur * 2 , left , mid , l , r , carry + segtree[cur].prop) ;
    int p2 = Query(cur * 2 + 1 , mid + 1 , right , l , r , carry + segtree[cur].prop) ;
    return (p1 + p2) ;
}
int main() {
    int test  = 0 ;
    int tc ;
    scanf("%d",&tc) ;
    while(tc--) {
        scanf("%s",str) ;
        int n = strlen(str) ;
        memset(segtree , 0 , sizeof(segtree)) ;
        Build(1 , 0 , n - 1) ;
        printf("Case %d:\n" ,++test) ;
        int q ;
        scanf("%d",&q) ;
        while(q--) {
            char ch ;
            scanf(" %c",&ch) ;
            if(ch == 'I') {
                int l , r ;
                scanf("%d%d",&l,&r) ;
                l-- , r-- ;
                if(l > r)
                    swap(l , r) ;
                Update(1 , 0 , n - 1 , l , r) ;
            } else if(ch == 'Q') {
                int id  ;
                scanf("%d",&id) ;
                id-- ;
                int ans = Query(1 , 0 , n - 1 , id , id) ;
                printf("%d\n", ans % 2);
            }
        }
    }
    return 0 ;
}
