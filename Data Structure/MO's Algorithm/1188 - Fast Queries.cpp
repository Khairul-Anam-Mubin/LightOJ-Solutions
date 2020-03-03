#include <bits/stdc++.h>
using namespace std ;

struct query {
    int l ;
    int r ;
    int idx ;
} ;
query Q[50010] ;
int ans[50010] ;
int ar[100010] ;
int freq[100010] ;
int cnt = 0 ;

#define BLOCK 555
bool cmp(query a , query b) {
    if(a.l / BLOCK != b.l / BLOCK)
        return a.l / BLOCK < b.l / BLOCK ;
    return a.r < b.r ;
}
void Add(int pos) {
    freq[ar[pos]]++ ;
    if(freq[ar[pos]] == 1)
        cnt++ ;
} 
void Remove(int pos) {
    freq[ar[pos]]-- ;
    if(freq[ar[pos]] == 0) 
        cnt-- ;
}
void MosAlgo(int q) {
    int ML = 0 , MR = -1 ;
    for(int i = 0 ; i < q ; i++) {
        int L = Q[i].l ;
        int R = Q[i].r ;
        while(ML > L) {
            ML-- ;
            Add(ML) ;
        }
        while(MR < R) {
            MR++ ;
            Add(MR) ;
        }
        while(ML < L) {
            Remove(ML) ;
            ML++ ;
        }
        while(MR > R) {
            Remove(MR) ;
            MR-- ;
        }
        ans[Q[i].idx] = cnt ;
    }
}
int main() {
    int tc , test = 0 ; 
    scanf("%d",&tc) ;
    while(tc--) {
        int n , q ;
        scanf("%d%d",&n,&q) ;
        for(int i = 0 ; i < n ; i++) {
            scanf("%d",&ar[i]) ;
        }
        for(int i = 0 ; i < q ; i++) {
            scanf("%d%d",&Q[i].l,&Q[i].r) ;
            Q[i].idx = i ;
            Q[i].l-- , Q[i].r-- ;
        }
        cnt = 0 ;
        sort(Q , Q + q , cmp) ;
        memset(freq , 0 , sizeof(freq)) ;
        MosAlgo(q) ;
        printf("Case %d:\n" ,++test) ;
        for(int i = 0 ; i < q ; i++) {
            printf("%d\n", ans[i]) ;
        }
    }
    return 0 ;
}
