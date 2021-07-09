#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int mod = 1e9+7;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        vector <int> a(n);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        sort (a.begin(), a.end());

        int val = a[n - k];
        // debug (n - k);
        int cnt = 0;
        for (int i = n - k + 1; i < n; i++) {
            if (a[i] == val) {
                cnt++;
            } else {
                break;
            }
        }

        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == val) tot++;
        }

        int ans = 1;
        int calc = tot - cnt;

        debug (tot);
        // for (int i = 0; i <= cnt && calc > 1; i++) {
            // ans *= calc--;
            // ans %= mod;
        // }

        // calculate tot choose cnt + 1


        printf("%lld\n", ans);
    }
}
