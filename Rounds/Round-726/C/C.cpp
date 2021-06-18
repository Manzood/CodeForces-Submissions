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
        vector <int> a(n);
        int f = -1, s = -1;
        int mi = 1e9 + 7;
        vector <bool> mark (n, false);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        sort (a.begin(), a.end());
        for (int i = 1; i < n; i++) {
            // debug (i);
            // debug (a[i]);
            if (a[i] - a[i - 1] < mi) {
                s = i;
                f = i - 1;
                mi = a[i] - a[i - 1];
            }
        }
        vector <int> ans;
        int smallest = 0;
        mark[s] = true;
        mark[f] = true;
        ans.push_back (a[f]);
        int large = s + 1;
        for (int i = 0; i < n - 2; i++) {
            // pick the largest number greater than current that hasn't been used
            if (large >= n) {
                ans.push_back (a[smallest++]);
            } else {
                ans.push_back (a[large++]);
            }
        }
        ans.push_back (a[s]);
        for (auto x: ans) {
            printf("%lld ", x);
        }
        printf("\n");
    }
}
