#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void update_tree (vector <int>& dp, int ind, string& s) {
    // update string before you call function
    // go to the parents, updating everything
    int n = dp.size();
    int cur = ind;
    while (cur >= 0) {
        if (s[cur] == '0') {
            if (2 * cur + 2 < n) {
                dp[cur] = dp[2 * cur + 2];
            } else {
                dp[cur] = 1;
            }
        } else if (s[cur] == '1') {
            if (2 * cur + 2 < n) {
                dp[cur] = dp[2 * cur + 1];
            } else {
                dp[cur] = 1;
            }
        } else {
            if (2 * cur + 2 < n) {
                dp[cur] = dp[2 * cur + 2] + dp[2 * cur + 1];
            } else {
                dp[cur] = 2;
            }
        }
        if (cur == 0) break;
        cur = (cur - 1) / 2;
    }
}

int32_t main() {
    int k;
    scanf("%lld", &k);
    string s;
    cin >> s;
    reverse (s.begin(), s.end());
    vector <int> dp ((1 << k) - 1, 1);
    // preprocess it
    int n = (1 << (k)) - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0' || s[i] == '?') {
            dp[i] = 0;
            if (2 * i + 2 < n) {
                dp[i] += dp[2 * i + 2];
            } else {
                if (s[i] == '?') dp[i] = 2;
                else dp[i] = 1;
            }
        }
        if (s[i] == '1' || s[i] == '?') {
            if (s[i] == '1') dp[i] = 0;
            if (2 * i + 2 < n) {
                dp[i] += dp[2 * i + 1];
            } else {
                if (s[i] == '?') dp[i] = 2;
                else dp[i] = 1;
            }
        }
    }
    // debug (s);
    // for (int i = 0; i < n; i++) {
        // printf("%lld ", dp[i]);
    // }
    // printf("\n");
    int q;
    scanf("%lld", &q);
    for (int i = 0; i < q; i++) {
        int ind;
        char c;
        scanf("%lld %c", &ind, &c);
        ind--;
        ind = n - ind - 1;
        s[ind] = c;
        // debug (s);
        update_tree (dp, ind, s);
        // for (int j = 0; j < n; j++) {
            // printf("%lld ", dp[j]);
        // }
        // printf("\n");
        printf("%lld\n", dp[0]);
    }
}
