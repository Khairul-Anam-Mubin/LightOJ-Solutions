#include <bits/stdc++.h>
using namespace std;

#define mxN 1429431
int segtree[4 * mxN] ;
int ans[100005] ;
 
void Build(int cur,int left,int right) {
    if( left == right) {
        segtree[cur] = (left & 1) ;
        return ;
    }
    int mid = (left + right) >> 1 ;
    Build((cur << 1) , left , mid) ;
    Build((cur << 1) | 1 , mid + 1, right) ;
    segtree[cur] = segtree[(cur << 1)] + segtree[(cur << 1) | 1] ;
    return ;
}
void Update(int cur ,int left ,int right ,int pos ) {
    if(left == right) {
        segtree[cur] = 0 ;
        return ;
    } 
    int mid = (left + right) >> 1 ;
    if( pos <= segtree[cur << 1] ) {
        Update(cur << 1, left, mid, pos) ;
    }
    else {
        Update((cur << 1) | 1, mid + 1, right , pos - segtree[(cur << 1)]) ;
    }
    segtree[cur] = segtree[(cur << 1)] + segtree[(cur << 1) | 1] ;
    return ;
}
int Query(int cur ,int left ,int right ,int pos) {
    if(left == right) { 
        return left ;
    }
    int mid = (left + right) >> 1 ;
    if(pos <= segtree[(cur << 1)]) {
        return Query((cur << 1), left , mid, pos) ;
    }
    else {
        return Query((cur << 1) | 1 , mid + 1, right, pos - segtree[(cur << 1)]) ;
    }
}
int main() {
    Build(1 , 1 , mxN) ;
    ans[1] = 1 ;
    for(int i = 2 ; i <= 100000 ; i++) {
        int kth = Query(1 , 1, mxN , i) ;
        ans[i] = kth ;
        for(int j = kth , cnt = 0 ; j <= mxN ; j += kth , cnt++) {
            Update(1 , 1, mxN , j - cnt) ;
        }
    }
    int tc , test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        int n ;
        scanf("%d",&n) ;
        printf("Case %d: %d\n", ++test , ans[n]) ;
    }
    return 0 ;
}
