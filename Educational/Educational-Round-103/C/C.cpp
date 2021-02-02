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
        vector <int> c(n);
        vector <int> a(n);
        vector <int> b(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &c[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &b[i]);
        }
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                if (i == 0) {
                    cur += abs(a[i+1] - b[i+1]);
                } else {
                    cur += c[i] - 1;
                }
            } else {
                ans = max(ans, cur + c[i] - 1);
                cur += min (a[i+1], b[i+1]) - 1;
                cur += c[i] - max (a[i+1], b[i+1]);
                if (abs(a[i+1] - b[i+1]) > cur) cur = abs(a[i+1] - b[i+1]);
                ans = max(cur, ans);
                if (a[i+1] == b[i+1]) {
                    cur = 0;
                }
            }
            ans = max(cur, ans);
            cur += 2;
        }
        printf("%lld\n", ans);
    }
}
