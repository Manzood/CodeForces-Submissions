#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        if (a.size() < b.size()) {
            swap (a, b);
        }
        int m = b.size();
        int n = a.size();
        int len = 0;
        string res = "";
        bool okay = true;
        bool found = false;
        int pos = 0;
        int respos = 0;
        while (okay && !found) {
            res += a;
            len += n;
            for (int i = 0; i < n; i++) {
                if (res[respos++] != b[pos++]) {
                    okay = false;
                    break;
                }
                pos %= m;
            }
            if (len % m == 0) found = true;
        }
        if (okay && found) {
            cout << res << "\n";
        } else {
            printf("-1\n");
        }
    }
}
