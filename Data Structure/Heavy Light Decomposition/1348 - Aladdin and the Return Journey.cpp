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
#define File         F();
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

void F(){
    #ifndef ONLINE_JUDGE 
        Fin;
        Fout; 
    #endif
}
template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> void Print(T ar[] , int a , int b) {for (int i = a; i + 1 <= b ; i++)cout << ar[i] << " ";cout << ar[b] << "\n";}
template <typename T> void Print(T ar[] , int n) {for (int i = 0; i + 1 < n; i++)cout << ar[i] << " ";cout << ar[n - 1] << "\n";} 
template <typename T> void Print(const vector<T> &v) {for (int i = 0; i + 1 < v.size() ; i++) cout << v[i] << " ";cout << v.back() << "\n";}


/**************************Segment tree*****************************/
struct SegmentTree {
    vector <long long> seg;
    vector <long long> lazy;
    vector <long long> ar;
    void Init(int N) {
        seg.assign(N << 2, 0);
        lazy.assign(N << 2 , 0);
        return;
    }
    void Init(const vector <long long> &s) {
        Init(s.size() + 1);
        ar = s;
        return;    
    }
    void PushDown(int cur , int left , int right) {
        seg[cur] += (right - left + 1) * lazy[cur];
        if (left != right) {        
            lazy[cur << 1] += lazy[cur];  
            lazy[cur << 1 | 1] += lazy[cur];
        }
        lazy[cur] = 0;   
        return;
    }
    long long Merge(long long x , long long y) {
        return x + y;
    }
    void Build(int cur , int left , int right) {
        lazy[cur] = 0;
        if (left == right) {
            seg[cur] = ar[left];
            return;
        }
        int mid = (left + right) >> 1;
        Build(cur << 1 , left , mid);
        Build(cur << 1 | 1 , mid + 1 , right);
        seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
        return;
    }
    void Update(int cur , int left , int right , int pos , long long val) {
        Update(cur , left , right , pos , pos , val);
        return;
    }
    void Update(int cur , int left , int right , int l , int r , long long val) {
        if (lazy[cur] != 0) PushDown(cur , left , right);         
        if (l > right || r < left) return;
        if (left >= l && right <= r) {
            lazy[cur] = val;
            PushDown(cur , left , right);
            return ;
        }
        int mid = (left + right) >> 1;
        Update(cur << 1 , left , mid , l , r , val);
        Update(cur << 1 | 1 , mid + 1 , right , l , r , val);
        seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
        return ;
    }
    long long Query(int cur , int left , int right , int l , int r) {
        if (l > right || r < left) return 0;
        if (lazy[cur] != 0) PushDown(cur , left , right);
        if (left >= l && right <= r) return seg[cur];
        int mid = (left + right) >> 1;
        long long p1 = Query(cur << 1 , left , mid , l , r);
        long long p2 = Query(cur << 1 | 1 , mid + 1 , right , l , r);
        return Merge(p1 , p2);
    }
} T;

/**************************HeavyLightDecomposition***********************/
/*  1.  All nodes are number from 0 to n - 1  */ 
/*  2.  Assign the graph by Init(graph) or simply Init(total nodes) and 
        call AddEdge(u , v) for all the edges */
/*  3.  Must be Take the node value from input directly or use the 
        TakeNodeVal(nodeval) to assigning the node value */
/*  4.  Call Build() to construct hld and segment tree */
/*  5.  simply use the path query by query(u , v) and update(pos , val) */

struct HeavyLightDecompose {
    vector <vector <int> > g ; // graph
    vector <long long> node_val;
    int N , root = 0;
    vector <int> depth , parent , sub;
    // HLD staffs
    int chain_no, indx;
    vector <int> chain_head , chain_ind;
    vector <int> node_serial , serial_node;
    vector <long long> segarr; // tree on linear format
    void Init(int n) {
        N = n;
        g.assign(N , {});
        node_val.clear();
        segarr.resize(N);
        depth.resize(N);
        parent.resize(N);
        sub.resize(N);
        chain_head.assign(N, -1);
        chain_ind.resize(N);
        node_serial.resize(N);
        serial_node.resize(N);
        return;
    }
    void Init(const vector <vector<int>> &_g) {
        Init(_g.size());
        g = _g;
        return;
    }
    void AddEdge(int u , int v) {
        g[u].push_back(v) ;
        g[v].push_back(u) ;
        return;
    }
    void TakeNodeVal(const vector <long long> &_node_val) {
        node_val = _node_val;
    }
    void Build() {
        Dfs(root);
        chain_no = 0, indx = 0;
        HLD(0);
        T.Init(segarr);
        T.Build(1 , 0 , N - 1);
    }
    void Dfs(int u, int par = -1) {
        sub[u] = 1;
        if (par == -1) {
            depth[u] = 0;
            parent[u] = -1;
        }
        for (int v : g[u]) {
            if (v == par) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            Dfs(v , u);
            sub[u] += sub[v];
            
        }
        return;
    }
    void HLD(int u , int par = -1) {
        if (chain_head[chain_no] == -1) chain_head[chain_no] = u;
        chain_ind[u] = chain_no;
        node_serial[u] = indx;
        serial_node[indx] = u;
        segarr[indx] = node_val[u]; // tree flatting..
        indx++;
        int heavychild = -1 , heavysize = 0;
        for (int v : g[u]) {
            if (v == par) continue;
            if (sub[v] > heavysize) {
                heavysize = sub[v];
                heavychild = v;
            }
        }
        if (heavychild != -1) HLD(heavychild , u);
        for (int v : g[u]) {
            if (v != par && v != heavychild) {
                chain_no++;
                HLD(v , u);
            }
        }
        return;
    }
    void Update(int p , int val) {
        T.Update(1 , 0 , N - 1, node_serial[p] , -node_val[p]);
        T.Update(1 , 0 , N - 1, node_serial[p] , val);
        node_val[p] = val;
    }
    long long Query(int u , int v) {
        long long ans = 0;
        for ( ; chain_ind[u] != chain_ind[v] ; v = parent[chain_head[chain_ind[v]]]) {
            if (depth[chain_head[chain_ind[u]]] > depth[chain_head[chain_ind[v]]])
                swap( u , v );
            ans += T.Query(1 , 0 , N - 1 , node_serial[chain_head[chain_ind[v]]] , node_serial[v]);
        }
        if (depth[u] > depth[v])
            swap(u , v);
        ans += T.Query(1 , 0 , N - 1 , node_serial[u] , node_serial[v]);
        return ans;
    }
} hd;
int main() {
    Faster
    Test {
        int n; cin >> n;
        hd.Init(n);
        vector <long long> pos;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            pos.PB(x);
        }
        hd.TakeNodeVal(pos);
        for (int i = 0; i < n - 1; i++) {
            int u , v; cin >> u >> v;
            hd.AddEdge(u , v);
        }
        hd.Build();
        int q; cin >> q;
        cout << "Case " << tc << ":\n";
        while (q--) {
            int x; cin >> x;
            if (x == 0) {
                int u , v; cin >> u >> v;
                cout << hd.Query(u , v) << "\n";
            } else if (x == 1) {
                int node , val;
                cin >> node >> val;
                hd.Update(node , val);
            }
        }
    }
    return 0;
}
