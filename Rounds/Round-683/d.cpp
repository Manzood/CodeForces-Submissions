#include "bits/stdc++.h"
using namespace std;
#define int long long
#define debug(x) cout << #x << " = " << x << endl;

int32_t main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    string a, b;
    cin >> a >> b;
    vector <vector <int>> dp(n+1);
    for (int i = 0; i <= n; i++) {
        dp[i].resize(m+1);
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    dp[1][1] = (a[0] == b[0]) ? 2 : 0;
    int ans = dp[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j && i == 1) continue;
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) - 1;
            }
            dp[i][j] = max(dp[i][j], 0LL);
            ans = max(dp[i][j], ans);
        }
    }
    printf("%lld\n", ans);
}
