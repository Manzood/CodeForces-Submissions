#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int inf = 1e9+7;

int32_t main() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    vector <int> ones;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 1) ones.push_back (i);
    }
    vector <vector <int>> dp (n, vector <int> (n, inf));
    for (int i = 0; i < n; i++) {
        // currently at pos i
        for (int j = 0; j < n; j++) {
            // using j zeroes as ending positions
            if (a[i] == 0) {
                // consider it as an ending position
                if (i > 0 && j > 0 && j < (int) ones.size() && dp[i-1][j-1] != inf) {
                    dp[i][j] = min (dp[i-1][j], dp[i-1][j-1] + abs (ones[j] - i));
                }
                if (j == 0 && j < (int) ones.size()) {
                    if (i > 0) dp[i][j] = min (dp[i-1][j], abs (ones[0] - i));
                    else dp[i][j] = abs (ones[0] - i);
                }
            } else {
                if (i > 0) dp[i][j] = dp[i-1][j];
            }
        }
    }
    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < n; j++) {
            // printf("%lld ", dp[i][j]);
        // }
        // printf("\n");
    // }
    printf("%lld\n", (int) ones.size() == 0 ? 0 : dp[n-1][(int)ones.size() - 1]);
}
