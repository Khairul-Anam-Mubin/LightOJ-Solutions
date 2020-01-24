#include <bits/stdc++.h>
using namespace std ;

#define FasterIO  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0) ;

struct node {
    bool endmark ;
    node *next[10] ;
    node() {
        for(int i = 0 ; i < 10 ; i++)
            next[i] = NULL ;
        endmark = 0 ;
    }
} ;
node *root ;
bool flag ;

void Insert(string &str) {
    int len = str.size() ;
    node *cur = root ;
    for(int i = 0 ; i < len ; i++) {
        int id = str[i] - '0' ;
        if(cur->next[id] == NULL) 
            cur->next[id] = new node() ;
        cur = cur->next[id] ;
    }
    cur->endmark = 1 ;
}
void Dfs(node *cur) {
    for(int i = 0 ; i < 10 ; i++) {
        if(cur->next[i]) {
            if(cur->endmark == 1) {
                flag = 0 ;
                return ;
            }
            Dfs(cur->next[i]) ;
        }
    }
}
void ClearMemory(node *cur) {
    for(int i = 0 ; i < 10 ; i++) {
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
        flag = 1 ;
        for(int i = 0 ; i < n ; i++) {
            string str ;
            cin >> str ;
            Insert(str) ;
        }
        Dfs(root) ;
        if(flag)
            cout << "Case " << ++test << ": YES\n" ;
        else
            cout << "Case " << ++test << ": NO\n" ;
        ClearMemory(root) ;
    }
    return 0 ;
}
