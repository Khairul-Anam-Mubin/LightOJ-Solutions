/***
**                      ALLAHU AKBAR
**
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <bits/stdc++.h>
using namespace std;
 
#define F            first
#define S            second  
#define PB           push_back
#define MP           make_pair
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0); 
#define Test         int test;cin >> test;for(int tc = 1; tc <= test; tc++)

#define MOD          998244353
#define INF9         2147483647
#define INF18        9223372036854775806
#define eps          1e-8 

const double pi = 2 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> void Print(T ar[] , int a , int b) {for (int i = a; i + 1 <= b ; i++)cout << ar[i] << " ";cout << ar[b] << "\n";}
template <typename T> void Print(T ar[] , int n) {for (int i = 0; i + 1 < n; i++)cout << ar[i] << " ";cout << ar[n - 1] << "\n";} 

/*....................Kruskal Algrithm.................*/
// mxN have to define before...
const int mxN = 101;
struct DSU {
    vector <int> parent;
    vector <int> siz;
    DSU(int mxN) {
        mxN <<= 1;
        parent.resize(mxN + 1);
        siz.resize(mxN + 1);
    }
    void Makeset(int n) {
        for (int i = 0 ; i <= n ; i++) {
            parent[i] = n + i;
            parent[n + i] = n + i;
            siz[n + i] = 1;
        }
    }
    int Find(int u) {
        if (parent[u] == u) return u ;
        return parent[u] = Find(parent[u]) ;
    }
    void Union(int u , int v) {
        u = Find(u);
        v = Find(v);
        if (u != v) {
            if (siz[u] < siz[v]) swap(u , v);
            parent[v] = u;
            siz[u] += siz[v];
        }
    }
    bool SameSet(int u , int v) {
        return (Find(u) == Find(v)) ;
    }
    void MoveUtoSetV(int u , int v) {
        if (SameSet(u , v)) return;
        int x = Find(u);
        int y = Find(v);
        siz[x]--;
        siz[y]++;
        parent[u] = y;
    }
    int Size(int u) {
        return siz[Find(u)];
    }
} dsu(mxN);
 
struct MST {
    vector <pair<int, pair<int , int>>> edges;
    vector <pair<int, pair<int , int>>> mstedges;
    int nodes , mstcost;
    void ProcessKruskal(int x) { // if x == 1 minimum spanning tree else maximum
        mstcost = 0;
        dsu.Makeset(nodes);
        mstedges.clear();
        if (x == 1)
            sort(edges.begin() , edges.end());
        else
            sort(edges.rbegin() , edges.rend());
        int cnt = 0 ;
        for (auto it : edges) {
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;
            if (!dsu.SameSet(u , v)) {
                dsu.Union(u , v);
                mstedges.push_back(make_pair(w , make_pair(u , v)));
                cnt++ , mstcost += w;
            }
            if (cnt + 1 == nodes)
                break ;
        }
    }
    void Init(int n , const vector<pair<int , pair<int , int>>> &_edges) {
        Init(n);
        edges = _edges;
    }
    void Init(int n) {
        nodes = n;
        mstcost = 0;
        dsu.Makeset(nodes);
        edges.clear();
        //mstedges.clear();
    }
    void AddEdge(int u, int v, int w) {
        edges.push_back(make_pair(w , make_pair(u , v)));
    }
    void ShowEdgeList() {
        for (auto it : edges) {
            cout << it.second.first << " -> " << it.second.first << " " ;
            cout << it.first << "\n";
        }
    }
    void ShowMSTEdgeList() {
        for (auto it : mstedges) {
            cout << it.second.first << " -> " << it.second.second << " ";
            cout << it.first << "\n";
        }    
    }
} mst;
int main() {
    Faster
    Test {
        int n; cin >> n;
        int u , v , w;
        mst.Init(n + 1);
        while (cin >> u >> v >> w) {
            if (u == 0 && v == 0 && w == 0) break;
            mst.AddEdge(u , v , w);
        }
        ll ans = 0;
        mst.ProcessKruskal(1);
        ans += mst.mstcost;
        //cout << mst.mstcost << "\n";
        mst.ProcessKruskal(2);
        ans += mst.mstcost;
        cout << "Case " << tc << ": ";
        if (ans % 2 == 0) {
            cout << ans / 2 << "\n";
        } else {
            cout << ans << "/" << 2 << "\n";
        }
    }
    return 0;
}
