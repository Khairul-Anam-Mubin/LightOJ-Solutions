#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        string s; cin >> s;
        if (s.substr(0 , 5) == "https") {
            cout << "Case " << i << ": " << s << "\n";
        } else {
            int len = s.size();
            cout << "Case " << i << ": https";
            for (int i = 4; i < len; i++) {
                cout << s[i];
            } 
            cout << "\n";
        }
    }
    return 0;
}
