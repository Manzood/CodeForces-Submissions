#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        vector <vector <int>> dp(k+1);
        for (int i = 0; i <= k; i++) {
            if (i == k) dp[i].resize(n + 1, 1);
            dp[i].resize(n + 1, 0);
        }
        int ans = 0;
        for (int i = k; i > 0; i--) {
            // if it's an even difference, check your left
            // otherwise check your right
            if ((k - i) % 2 == 0) {
                // even
                for (int j = 1; j <= n && i != k; j++) {
                    if (j > 1 && i < k) dp[i][j] += dp[i+1][j-1];
                    if (j > 1) dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
                ans += dp[i][n];
                ans %= mod;
            } else {
                // odd
                for (int j = n; j >= 0 && i != k; j--) {
                    if (j < n && i < k) dp[i][j] += dp[i+1][j+1];
                    if (j < n - 1) dp[i][j] += dp[i][j+1];
                    dp[i][j] %= mod;
                }
                ans += dp[i][0];
                ans %= mod;
            }
        }
        // if (n == 1) {
            // for (int i = k; i >= 0; i--) {
                // for (int j = 0; j <= n; j++) {
                    // printf("%lld ", dp[i][j]);
                // }
                // printf("\n");
            // }
        // }
        printf("%lld\n", ans);
    }
}
