/***
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
template <typename T> string ToBinary(T n) {string r ;while(n != 0) {r = ( n % 2 == 0 ? "0" : "1" ) + r ; n >>= 1;} return r ;}
 
char Uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char Lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool Isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
int Strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
string Intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> Linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.push_back(s);return v;}
 
#define MOD 4294967296
#define INF9 2147483647
#define INF18 9223372036854775807
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define eps 1e-8
 
//int dx[] = {0 , 0 , -1 , 1 , -1 , -1 , 1 , 1 , 0} ;
//int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 , -1 , 1 , 0} ;
//int dx[] = {0 , 0 , -1 , 1} ; // right , left , forward , backward
//int dy[] = {1 , -1 , 0 , 0} ;
 
//scanf(" %[^\n]", str) ;

// works in O(n) ..
string BigintSum(string &str1 , string &str2) {
    if((int)str1.size() < (int)str2.size())
        swap(str1 , str2) ;
    int len1 = (int)str1.size() ; 
    int len2 = (int)str2.size() ;
    int n = len2 ;
    int carry = 0 ;
    string sum ;
    for(int i = len1 - 1 , j = len2 - 1 ; i >= 0 ; i-- , j--){
        int x ;
        if(n){
            x = str1[i] - '0' + str2[j] - '0' + carry ;
            n-- ;
        } else
            x = str1[i] - '0' + carry ;
        carry = x / 10 ;
        x = x % 10 ;
        sum.push_back(x +'0') ;
    }
    if(carry) sum.push_back(carry + '0') ;
    reverse(sum.begin() ,sum.end()) ;
    return sum ;
}
//take to string as numbers and returns the product of these two numbers to strings
// On worst case BigintProd take O(n^2) complexity
string BigintProd(string &str1 , string &str2) {
    if((int)str1.size() < (int)str2.size())
        swap(str1 , str2) ;
    int len1 = (int)str1.size() ; 
    int len2 = (int)str2.size() ;
    int carry = 0 , cnt = 1 ;
    string prod , pro ;
    for(int i = len2 - 1 ; i >= 0 ; i--) {
        carry = 0 ;
        for(int j = len1 - 1 ; j >=0 ; j--) {
            int x = (str2[i] - '0') * (str1[j] - '0') + carry ;
            carry = x / 10 ;
            x = x % 10 ;
            prod.push_back( x+'0') ;
        }
        if(carry) prod.push_back(carry +'0') ;
        reverse(prod.begin() , prod.end()) ;
        if(cnt == 1) {
            pro = prod ;
            cnt++ ;
            prod.clear() ;
        }
        else{
            pro = BigintSum(pro , prod) ;
            prod.clear() ;
        }
        for(int k = len2 - 1 ; k >= i ; k--)
            prod.push_back('0') ;
    }
    //return "0" if any multiply apply with 0
    if(pro[0] == '0' && pro.size() > 1) pro = "0" ;
    return pro ;
}

map <int , int> mp ;

// Optimized sieve O(nloglogn)
#define mxN 1000
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

// prime factor of a number n
template <typename T> void PrimeFactors(T n) {
    //vector <T> pf ;
    for(T i = 0 ; i < prime.size() && prime[i] * prime[i] <= n ; i++) {
        if(n % prime[i] == 0) {
            T cnt = 0 ;
            while(n % prime[i] == 0) {
                n /= prime[i] ;
                cnt++ ;
                //pf.push_back(prime[i]) ;
            }
            mp[prime[i]] = max(mp[prime[i]] , cnt) ;
        }
    }
    if(n != 1) {
        //pf.push_back(n) ;
        mp[n] = max(mp[n] , 1) ;
    }
}
int main() {
    Sieve(mxN) ;
    int tc , test = 0 ;
    cin >> tc ;
    while(tc--) {
        int n ; cin >> n ;
        for(int i = 0 ; i < n ; i++) {
            int x ; cin >> x ;
            PrimeFactors(x) ;
        }
        for(auto it : mp) {
            mp[it.F] = Pow(it.F , it.S) ;
        }
        string lcm = "1" ;
        for(auto it : mp) {
            string s = Intostr(it.S) ;
            lcm = BigintProd(lcm , s) ;
        }
        cout << "Case " << ++test << ": " ;
        cout << lcm << "\n" ;
        mp.clear() ;
    }

    return 0 ;
}
