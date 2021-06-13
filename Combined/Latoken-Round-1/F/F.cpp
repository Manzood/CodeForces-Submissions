#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> cnt(m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &cnt[i]);
    }
    vector <int> highest(m, 1e9+7);
    int ans = 0;
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (a[i][j] == '#') {
                highest[j] = i;
            }
        }
    }
    int p = -1;
    for (int j = 0; j < m; j++) {
        if (highest[j] < n && p == -1) {
            ans++;
            p = 0;
        }
        if (highest[j] >= n) continue;
        int st = highest[j];
        if (j + 1 < m && highest[j + 1] < highest[j]) {
            bool will_fall = true;
            for (int k = st; k > highest[j + 1]; k--) {
                if (a[k][j+1] != '#') will_fall = false;
            }
            if (!will_fall) ans++;
        }
        if (ans == 0) {
            if (j > 0 && highest[j] > highest[j-1]) {
                ans++;
            }
        }
        if (cnt[j] == 0) p = -1;
        debug (ans);
    }
    printf("%lld\n", ans);
}
