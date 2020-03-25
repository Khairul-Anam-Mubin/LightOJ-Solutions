#include <bits/stdc++.h>
using namespace std ;

const int INF9 = 10000000 ;
const int mxN = 50010 ;
const int po = 20 ;

vector <pair<int ,pair<int, int>>> edges ;
int dsu[mxN] ;

vector <pair<int , int>> g[mxN] ;

int level[mxN] , weight[mxN] , parent[mxN];
int SpTab[mxN][po] ;
int MX[mxN][po] ;
int N , root ;

int LCA(int u , int v) {
    int mx = -INF9 ;
    if(level[u] < level[v])  swap(u , v) ;
    int log ;
    for(log = 1 ; (1 << log) <= level[u] ; log++);
    log-- ;
    for(int i = log ; i >= 0 ; i--) {
        if(level[u] - (1 << i) >= level[v]) {
            mx = max(mx , MX[u][i]) ;
            u = SpTab[u][i] ;
        }
    }
    if(u == v) return mx ;
    for(int i = log ; i >= 0 ; i--) {
        if(SpTab[u][i] != -1 && SpTab[u][i] != SpTab[v][i]) {
            mx = max(mx , max(MX[u][i] , MX[v][i])) ;
            u = SpTab[u][i] ;
            v = SpTab[v][i] ;
        }
    }
    mx = max(mx , max(MX[u][0] , MX[v][0])) ;
    return mx ;
}
void Dfs(int u , int par = -1) {
    if(par == -1) {
        level[u] = weight[u] = 0 ;
        parent[u] = -1 ;
    }
    for(auto it : g[u]) {
        int v = it.first ;
        int w = it.second ;
        if(v != par) {
            parent[v] = u ;
            weight[v] = w ;
            level[v] = level[u] + 1 ;
            Dfs(v , u) ;
        }
    }
}
void SparseTable() {
    Dfs(root) ;
    for(int i = 0 ; i < N ; i++) {
        SpTab[i][0] = parent[i] ;
        MX[i][0] = weight[i] ;
    }
    for(int j = 1 ; (1 << j) < N ; j++) {
        for(int i = 0 ; i < N ; i++) {
            if(SpTab[i][j - 1] != -1) {
                SpTab[i][j] = SpTab[SpTab[i][j - 1]][j - 1] ;
                MX[i][j] = max(MX[i][j - 1] , MX[SpTab[i][j - 1]][j - 1]) ;
            }
        }
    }
}
int Find(int u) {
    if(dsu[u] == u)
        return u ;
    return dsu[u] = Find(dsu[u]) ;
}
void Union(int u , int v) {
    u = Find(u) ;
    v = Find(v) ;
    if(u != v) {
        dsu[u] = v ;
    }
}
bool Sameset(int u , int v) {
    return (Find(u) == Find(v)) ;
}
void Makeset(int n) {
    for(int i = 0 ; i <= n + 1 ; i++)
        dsu[i] = i ;
}
void KruskalAlgo(int n) {
    Makeset(n) ;
    sort(edges.begin() , edges.end()) ;
    int cnt = 0  ;
    for(auto it : edges) {
        int u = it.second.first ;
        int v = it.second.second ;
        int w = it.first ;
        if(!Sameset(u , v)) {
            Union(u , v) ;
            g[u].push_back(make_pair(v , w)) ;
            g[v].push_back(make_pair(u , w)) ;
            cnt++ ;
        }
        if(cnt + 1 == n)
            break ;
    }
}
void Show_Graph(int n) {
    for(int i = 0 ; i < n ; i++) {
        cout << i << " : " ;
        for(auto it : g[i]) {
            cout << it.first << " -> " ;
        }
        cout << "\n" ;
    }
}
void Reset() {
    edges.clear() ;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; (1 << j) < N ; j++) {
            SpTab[i][j] = -1 ;
            MX[i][j] = -INF9 ;
        }
        g[i].clear() ;
    }
}
void Solve() {
    int n , m ;
    scanf("%d%d",&n,&m) ;
    N = n ;
    root = 0 ;
    Reset() ;
    for(int i = 0 ; i < m ; i++) {
        int u , v , w ;
        scanf("%d%d%d",&u,&v,&w) ;
        u-- , v-- ;
        edges.push_back(make_pair(w , make_pair(u , v))) ;
    }
    KruskalAlgo(n) ;
    //Show_Graph(n) ;
    SparseTable() ;
    int q ;
    scanf("%d",&q) ;
    while(q--) {
        int u , v ;
        scanf("%d%d",&u,&v) ;
        u-- , v-- ;
        int ans = LCA(u , v) ;
        printf("%d\n", ans) ;
    }
}
int main() {
    int tc , test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        printf("Case %d:\n",++test );
        Solve() ;
    }
    return 0 ;  
}
