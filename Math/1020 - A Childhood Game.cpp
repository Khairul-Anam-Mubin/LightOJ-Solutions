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

int main() {
    Faster
    //cin.tie(0);cout.tie(0); 
    Test {
        ll n; cin >> n;
        string s; cin >> s;
        /*
        ll dp[n + 5];
        // for alice start
        dp[0] = 1; 
        dp[1] = 0;
        for (int i = 2 ; i <= n ; i++) {
            dp[i] = 0;
            if (dp[i - 1] == 0 || dp[i - 2] == 0) dp[i] = 1;
        }
        Print(dp ,1 , n);
        // for bob start
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = 0;
            if (dp[i - 1] == 0 || dp[i - 2] == 0) dp[i] = 1;
        }
        Print(dp , 1 , n);
        // so there is a mod 3 pattern
        */
        n %= 3;
        cout << "Case " << tc << ": ";
        if (s == "Bob") {
            if (n) cout << "Bob\n";
            else cout << "Alice\n";
        } else {
            if (n == 2 || n == 0) cout << "Alice\n";
            else cout << "Bob\n";
        }
    }
    return 0;
}
