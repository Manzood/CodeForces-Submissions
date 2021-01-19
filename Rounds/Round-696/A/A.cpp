#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        string out;
        int p = -1;
        for (int i = 0; i < n; i++) {
            int val = s[i] - '0';
            val++;
            char add = '1';
            if (i > 0 && val == p) {
                val--;
                add = '0';
            }
            p = val;
            out += add;
        }
        cout << out << "\n";
    }
}
