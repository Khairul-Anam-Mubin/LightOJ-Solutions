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
 
typedef unsigned long long ull;
typedef long long ll;
const double pi = acos(-1.0);
 
// Functions && Templates...

template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template <typename T> T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
template <typename T> T Exgcd(T a,T b,T &x,T &y) {if(a<0){T d=Exgcd(-a,b,x,y);x=-x;return d;}   if(b<0){T d=Exgcd(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=Exgcd(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInvPrime (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T ModInvNotPrime(T a , T m) {T x , y ;Exgcd(a , m , x , y) ;x %= m ;if(x < 0) x += m ;return x ;}
template <typename T> typename std::vector<T>::iterator Insert_sorted (std :: vector<T> & vec, T const& item) {return vec.insert (std::upper_bound( vec.begin(), vec.end(), item ), item);}
template <typename T> inline string ToBinary(T n) {string r ;while(n != 0) {r = ( n % 2 == 0 ? "0" : "1" ) + r ; n >>= 1;} return r ;}
 
char Uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char Lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool Isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
int Strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
string Intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> Linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.push_back(s);return v;}
 
#define MOD 4294967296
#define INF9 2147483647
#define INF18 9223372036854775806
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define eps 1e-8

//int dx[] = {0 , 0 , -1 , 1 , -1 , -1 , 1 , 1 , 0} ;
//int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 , -1 , 1 , 0} ;

//int dx[] = {0 , 0 , -1 , 1} ; // right , left , forward , backward
//int dy[] = {1 , -1 , 0 , 0} ; 

//scanf(" %[^\n]", str) ;

#define mxN 500000
bool isp[mxN + 10] ;
vector <long long> prime ;
template <typename T> void Sieve(T n){
    for(T i = 1 ; i <= n ; i++) isp[i] = 0 ;
    isp[0] = isp[1] = 1 ;
    for(T i = 4 ; i <= n ; i += 2) isp[i] = 1 ;
    for(T i = 3 ; i * i <= n ; i += 2) {
        if(!isp[i]) {
            for(T j = i * i ; j <= n ; j += i + i) {
                isp[j] = 1 ;
            }
        }
    }
    prime.push_back(2);
    for(T i = 3 ; i <= n ; i += 2) {
        if(!isp[i]) {
            prime.push_back(i) ;
        }
    }
}
long long SementedSieve(long long a , long long b) {
    bool seg[100010] ;
    if(a == 1)
        a++ ;
    if(b < 2)
        return 0 ;
    long long sqrtn = sqrt(b) + 1 ;
    memset(seg , 0 , sizeof(seg)) ;
    for(int i = 0 ;  i < prime.size() && prime[i] <= sqrtn ; i++) {
        long long p = prime[i] ;
        long long j = p * p ;
        if(j < a) {
            j = ((a + p - 1) / p) * p ;
        }
        for( ; j <= b ; j += p) {
            seg[j - a] = 1 ;
        }
    }
    long long cnt = 0 ;
    for(int i = a ; i <= b ; i++) {
        if(seg[i - a] == 0)
            cnt++ ;
    }
    return cnt ;
}
int main() {
    Sieve(mxN) ;
    int tc , test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        long long a , b ;
        scanf("%lld%lld",&a,&b) ;
        long long ans = SementedSieve(a , b) ;
        printf("Case %d: %lld\n", ++test , ans) ;
    }
    return 0 ;
}
