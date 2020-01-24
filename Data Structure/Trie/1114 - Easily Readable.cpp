#include <bits/stdc++.h>
using namespace std ;

#define FasterIO  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0) ;

vector<string> linetostr(string &str){
    string s;
    vector <string> v ;
    istringstream is(str);
    while(is >> s)v.push_back(s);
    return v;
}
int main() {
    //FasterIO
    int tc ,test = 0 ;
    cin >> tc ;
    while(tc--) {
        int n ;
        cin >> n ;
        map <string , int> mp ;
        while(n--) {
            string str ;
            cin >> str ;
            if((int)str.size() > 2)
                sort(&str[1] , &str[((int)str.size()) - 1]) ;
            //cout << str << "\n" ;
            mp[str]++ ;
        }
        cout << "Case " << ++test << ":\n" ;
        int m ;
        cin >> m ;
        string ss ;
        getline(cin , ss) ;
        while(m--) {
            getline(cin , ss) ;
            vector <string> v = linetostr(ss) ;
            for(int i = 0 ; i < v.size() ; i++) {
                if((int)v[i].size() > 2)
                    sort(&v[i][1] , &v[i][((int)v[i].size()) - 1]) ;
            }
            long long ans = 1 ;
            for(int i = 0 ; i < v.size() ; i++) {
                ans *= mp[v[i]] ;
            }
            cout << ans << "\n" ;
        }
        mp.clear() ;
    }
    return 0 ;
}
