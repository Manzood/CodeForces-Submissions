#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        vector <int> a(n), b(n), c(m);
        // marker array
        vector <int> placeholder(n, -1);
        vector <vector <int>> changes(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &b[i]);
            placeholder[b[i]-1] = i;
            if (a[i] != b[i]) {
                changes[b[i]-1].push_back(i);
            }
        }
        for (int i = 0; i < m; i++) {
            scanf("%lld", &c[i]);
        }
        vector <int> ans(m);
        bool possible = true;
        for (int i = 0; i < m; i++) {
            int sz = changes[c[i]-1].size();
            if (sz > 0) {
                ans[i] = changes[c[i]-1][sz-1] + 1;
                changes[c[i]-1].pop_back();
            } else {
                if (placeholder[c[i]-1] != -1) ans[i] = placeholder[c[i]-1] + 1;
                else ans[i] = -1;
            }
        }
        for (int i = 0; i < m; i++) {
            if (ans[i] == -1) {
                if (i < m - 1) {
                    ans[i] = ans[m-1];
                } else {
                    possible = false;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int sz = changes[i].size();
            if (sz > 0) possible = false;
        }
        if (possible) {
            printf("YES\n");
            for (int i = 0; i < m; i++) {
                printf("%lld ", ans[i]);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
}
