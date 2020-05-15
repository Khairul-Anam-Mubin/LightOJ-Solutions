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

// c++ math templates
template <typename T> T Gcd(T a,T b){
    if(a < 0)return Gcd(-a,b);
    if(b < 0)return Gcd(a,-b);
    return (b == 0)?a:Gcd(b,a%b);
}
template <typename T> T Lcm(T a,T b) {
    if(a < 0)return Lcm(-a,b);
    if(b < 0)return Lcm(a,-b);
    return a*(b/Gcd(a,b));
}
template <typename T> T Exgcd(T a,T b,T &x,T &y) {
    if(a < 0){
        T d = Exgcd(-a,b,x,y);
        x =- x;
        return d;
    }
    if(b < 0){
        T d = Exgcd(a,-b,x,y);
        y =- y;
        return d;
    }
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    else{
        T d = Exgcd(b,a%b,x,y);
        T t = x;
        x = y;
        y = t - (a/b) * y;
        return d;
    }
}
template <typename T> T BigMod (T b,T p,T m){
    if (p == 0) 
        return 1;
    if (p % 2 == 0){
        T s = BigMod(b , p/2 , m) ;
        return (( s % m ) * ( s % m )) % m ;
    }
    return ((b % m) * (BigMod(b , p - 1, m ) % m )) % m ;
}
template <typename T> T ModInvPrime (T b,T m) {
    return BigMod(b , m - 2 , m);
}
template <typename T> T ModInvNotPrime(T a , T m) {
    T x , y;
    Exgcd(a , m , x , y);
    x %= m;
    if(x < 0) 
        x += m;
    return x;
}
template <typename T> bool IsPrime(T n) {
    if(n == 0 || n == 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0 ;
    for(T i = 3 ; i * i <= n ; i += 2) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
template <typename T> string ToBinary(T n) {
    string r;
    while(n != 0) {
        r = ( n % 2 == 0 ? "0" : "1" ) + r; 
        n >>= 1;
    } 
    return r;
}
template <typename T> T Mod(T a, T m) {
    return (((a % m) + m)%m);
}

int main() {
    Faster
    Test {
        ll a , b , c , d;
        cin >> a >> b >> c >> d;
        ll g = Gcd(Abs(a - c) , Abs(b - d)) + 1;
        cout << "Case " << tc << ": " << g << "\n"; 
    }
    return 0; 
}
