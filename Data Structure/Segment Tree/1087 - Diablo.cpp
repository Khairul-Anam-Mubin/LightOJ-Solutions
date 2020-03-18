#include <bits/stdc++.h>
using namespace std ;
 
#define mxN 200000
long long id[mxN + 10] ;
 
struct node {
    long long val , sum ;
} segtree[mxN * 4] ;
 
void Build(int cur , int left , int right) {
    if(left == right ) {
        segtree[cur].val = id[left] ;
        if(id[left] != 0)
            segtree[cur].sum = 1 ;
        return ;
    }
    int mid = (left + right) / 2 ;
    Build(cur * 2 , left , mid) ;
    Build(cur * 2 + 1 , mid + 1 , right) ;
    segtree[cur].sum = segtree[cur * 2].sum + segtree[cur * 2 + 1].sum ;
    return ;
}
long long Query(int cur , int left , int right , int pos) {
    segtree[cur].sum-- ;
    if(left == right) {
        id[left] = 0 ;
        return segtree[cur].val ;
    }
    int mid = (left + right) / 2 ;
    if(pos <= segtree[cur * 2].sum) {
        return Query(cur * 2 , left , mid , pos) ;
    } else {
        return Query(cur * 2 + 1 , mid + 1 , right , pos - segtree[cur * 2].sum) ;
    }
}
void Update(int cur , int left , int right , int pos , long long val) {
    if(pos == left && pos == right) {
        id[pos] = val ;
        segtree[cur].sum = 1 ;
        segtree[cur].val = val ;
        return ;
    }
    int mid = (left + right) / 2 ;
    if(pos <= mid)
        Update(cur * 2 , left , mid , pos , val) ;
    else
        Update(cur * 2 + 1, mid + 1 , right , pos , val) ;
    segtree[cur].sum = segtree[cur * 2].sum + segtree[cur * 2 + 1].sum ;
    return ;
}
int main() {
    int tc ,test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        int n , q ;
        scanf("%d%d",&n,&q) ;
        memset(id , 0 , sizeof(id)) ;
        memset(segtree , 0 , sizeof(segtree)) ;
        for(int i = 1 ; i <= n ; i++) {
            scanf("%lld",&id[i]) ;
        }
        Build(1 , 1 , mxN) ;
        printf("Case %d:\n", ++test);
        while(q--) {
            char ch ;
            scanf(" %c ",&ch) ;
            if(ch == 'c') {
                int pos ;
                scanf("%d",&pos) ;
                if(pos > segtree[1].sum) {
                    printf("none\n");
                } else {
                    printf("%d\n",Query(1 , 1 , mxN , pos));
                }
            } else if(ch == 'a') {
                long long val ;
                scanf("%lld",&val) ;
                n++ ;
                Update(1 , 1 , mxN , n , val) ;
            }
        }
    }
    return 0 ;
}
