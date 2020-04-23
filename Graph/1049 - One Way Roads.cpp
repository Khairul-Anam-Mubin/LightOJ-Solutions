/***
**     Allahu Akbar
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
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree < 
        int, 
        null_type , 
        less < int > , 
        rb_tree_tag , 
        tree_order_statistics_node_update > 
        ordered_set ;
// *st.find_by_order(k) ; kth element
//  st.order_of_key(k) ; number of element less than k  
*/
template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template <typename T> T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
template <typename T> T Exgcd(T a,T b,T &x,T &y) {if(a<0){T d=Exgcd(-a,b,x,y);x=-x;return d;}   if(b<0){T d=Exgcd(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=Exgcd(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInvPrime (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T ModInvNotPrime(T a , T m) {T x , y ;Exgcd(a , m , x , y) ;x %= m ;if(x < 0) x += m ;return x ;}
template <typename T> inline string ToBinary(T n) {string r ;while(n != 0) {r = ( n % 2 == 0 ? "0" : "1" ) + r ; n >>= 1;} return r ;}
 
template<typename T> void Print(T ar[] , int a , int b) {for (int i = a; i + 1 <= b ; i++)cout << ar[i] << " ";cout << ar[b] << "\n";}
template<typename T> void Print(T ar[] , int n) {for (int i = 0; i + 1 < n; i++)cout << ar[i] << " ";cout << ar[n - 1] << "\n";}
 
template <typename T> typename std::vector<T>::iterator Insert_sorted (std :: vector<T> & vec, T const& item) {return vec.insert (std::upper_bound( vec.begin(), vec.end(), item ), item);} 
char Uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char Lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool Isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
long long Strtoint(string str){stringstream ss(str);long long x = 0;ss >> x ;return x ;}
string Intostr(long long x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> Linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.push_back(s);return v;} 
 
const double pi = 2 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define MOD 998244353
#define INF9 2147483647
#define INF18 9223372036854775806
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define eps 1e-8
 
//int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
//int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
//int dx[] = {0 , 0 , -1 , 1} ; // right , left , forward , backward
//int dy[] = {1 , -1 , 0 , 0} ; 
 
//scanf(" %[^\n]", str) ;

#define Test int tc,tk=1;cin>>tc;while(tc--){Solve(tk++);}

struct node {
    int left , right;
};
node g[101];
void Solve(int tk) {
    int n; scanf("%d",&n);
    memset(g , 0 , sizeof(g));
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int u , v , w;
        scanf("%d%d%d",&u , &v , &w);
        if (g[u].left == 0 && g[v].right == 0) {
            g[u].left = g[v].right = 1;
            l += w;
        } else {
            g[u].right = g[v].left = 1;
            r += w;
        }
    }
    printf("Case %d: %d\n",tk,min(l , r));
}
int main() {
    //FasterIO
    Test
    return 0;
}
