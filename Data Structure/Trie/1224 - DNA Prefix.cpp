#include <bits/stdc++.h>
using namespace std ;

#define FasterIO  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0) ;

struct node {
    bool endmark ;
    node *next[4] ;
    long long freq ,curlen ;
    node() {
        for(int i = 0 ; i < 4 ; i++)
            next[i] = NULL ;
        endmark = 0 ;
        freq = 0 ;
        curlen = 0 ;
    }
} ;
node *root ;
long long ans ;

void Insert(string &str) {
    int len = str.size() ;
    node *cur = root ;
    for(int i = 0 ; i < len ; i++) {
        int id ;
        if(str[i] == 'A')
            id = 0 ;
        else if(str[i] == 'C')
            id = 1 ;
        else if(str[i] == 'G')
            id = 2 ;
        else if(str[i] == 'T')
            id = 3 ;  
        if(cur->next[id] == NULL) 
            cur->next[id] = new node() ;
        (cur->next[id]->freq)++ ;
        cur->next[id]->curlen = i + 1 ;
        cur = cur->next[id] ;
    }
    cur->endmark = 1 ;
}
void Dfs(node *cur) {
    for(int i = 0 ; i < 4 ; i++) {
        if(cur->next[i]) {
            ans = max(ans , cur->next[i]->curlen * cur->next[i]->freq ) ;
            Dfs(cur->next[i]) ;
        }
    }
}
void ClearMemory(node *cur) {
    for(int i = 0 ; i < 4 ; i++) {
        if(cur->next[i])
            ClearMemory(cur->next[i]) ;
    }
    delete(cur) ;   
}
int main() {
    FasterIO
    int tc ,test = 0 ;
    cin >> tc ;
    while(tc--) {
        int n ;
        cin >> n ;
        root = new node() ;
        ans = 0 ;
        for(int i = 0 ; i < n ; i++) {
            string str ;
            cin >> str ;
            Insert(str) ;
        }
        Dfs(root) ;
        cout << "Case " << ++test << ": " << ans << "\n" ;
        ClearMemory(root) ;
    }
    return 0 ;
}
