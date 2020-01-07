#include <bits/stdc++.h>
 
using namespace std ;
 
#define INF 1e9
#define mxN 100000
int ar[mxN + 5] ;
int segtree[mxN * 4] ;
 
void Build(int ar[] , int cur ,int left , int right) {
    if(left == right) {
        segtree[cur] = ar[left] ;
        return ;
    }
    int mid = ( left + right ) / 2 ;
    Build(ar , cur * 2 , left , mid) ;
    Build(ar , cur * 2 + 1 , mid + 1 , right) ;
    segtree[cur] = min(segtree[cur * 2] , segtree[cur * 2 + 1]) ;
    return ;
}
int MinQuery(int cur ,int left ,int right ,int i , int j) {
    if(i > right || j < left)
        return INF ;
    if(left >= i && right <= j)
        return segtree[cur] ;
    int mid = (left + right) / 2 ;
    int q1 = MinQuery(cur * 2 , left , mid , i , j) ;
    int q2 = MinQuery(cur * 2 + 1 , mid + 1 ,right , i , j) ;
    return min(q1 , q2) ;
}
int main() {
    int tc ;
    scanf( "%d" ,&tc) ;
    for(int i = 1 ; i <= tc ; i++) {
        int n , q ;
        scanf( "%d%d" ,&n ,&q) ;
        for(int j = 0 ; j < n ; j++) {
            scanf( "%d" ,&ar[j]) ;
        }
        Build(ar , 1 , 0 , n - 1) ;
        printf("Case %d:\n", i) ;
        while(q--) {
            int left , right ;
            scanf( "%d%d" ,&left ,&right) ;
            int ans = MinQuery(1 , 1 , n , left , right) ;
            printf("%d\n", ans) ;
        }
    }
    return 0 ;
}
 
