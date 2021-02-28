#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        // count the number of visits as well
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        vector <int> passes(n, 0);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 1) {
                for (int j = i + 2; j < n && j < i + a[i] + 1; j++) {
                    passes[j]++;
                }
            }
            if (passes[i] >= a[i]) {
                if (i + 1 < n) passes[i + 1] += passes[i] - a[i] + 1;
            }
            if (a[i] - passes[i] > 1) {
                ans += a[i] - passes[i] - 1;
            }
        }
        // for (int i = 0; i < n; i++) {
            // printf("%lld ", passes[i]);
        // }
        // printf("\n");
        printf("%lld\n", ans);
    }
}
