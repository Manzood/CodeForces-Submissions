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
        vector <int> a(n), b(n), pref(n);
        int f = 0;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
            if (i == 0) pref[i] = a[i];
            else pref[i] = pref[i-1] + a[i];
        }
        cin >> s;
        for (int i = 0; i < n; i++) {
            b[i] = s[i] - '0';
        }
        bool ans = true;
        for (int i = n - 1; i >= 0; i--) {
            if ((a[i] ^ f) != b[i]) {
                if (i % 2 != 1 || pref[i] != (i + 1) / 2) {
                    ans = false;
                } else {
                    f ^= 1;
                }
            }
        }
        ans ? printf("YES\n") : printf("NO\n");
    }
}
