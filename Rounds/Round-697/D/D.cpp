#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        vector <int> a(n);
        vector <int> b(n);
        vector <int> ones;
        vector <int> twos;
        int ans = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%lld", &b[i]);
            if (b[i] == 1) {
                ones.push_back (a[i]);
            } else {
                twos.push_back (a[i]);
            }
        }


        sort (ones.begin(), ones.end(), greater<int>());
        sort (twos.begin(), twos.end(), greater<int>());


        for (int i = 1; i < (int) twos.size(); i++) {
            twos[i] += twos[i-1];
        }

        // for (int i = 0; i < (int) ones.size(); i++) {
            // printf("%lld ", ones[i]);
        // }
        // printf("\n");
        // for (int i = 0; i < (int) twos.size(); i++) {
            // printf("%lld ", twos[i]);
        // }
        // printf("\n");

        bool found = false;
        int s = 0;
        for (int i = 0; i < (int) ones.size(); i++) {
            if (s >= m) {
                ans = min (i, ans);
                found = true;
            }
            int j = lower_bound (twos.begin(), twos.end(), m - s) - twos.begin();
            if (j < (int) twos.size()) {
                if (j > 0) {
                    ans = min (i + 2 * (j + 1), ans);
                } else {
                    if (m - s > 0) {
                        ans = min (i + 2 * (j + 1), ans);
                    } else {
                        ans = min (i, ans);
                    }
                }
                // debug (i);
                // debug (j);
                found = true;
            }
            s += ones[i];
        }

        int j = lower_bound (twos.begin(), twos.end(), m - s) - twos.begin();
        // debug (j);
        if (j < (int) twos.size()) {
            if (j > 0) {
                ans = min ((int) ones.size() + 2 * (j + 1), ans);
            } else {
                if (s >= m) {
                    ans = min(ans, (int) ones.size());
                } else {
                    ans = min (ans, (int) ones.size() + 2);
                }
            }
            found = true;
        } else {
            if (s >= m) {
                ans = min (n, ans);
                found = true;
            }
        }

        if (!found) {
            printf("-1\n");
        } else {
            printf("%lld\n", ans);
        }
    }
}
