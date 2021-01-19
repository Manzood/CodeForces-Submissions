#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
// solve it properly tomorrow, and solve D as well

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        n *= 2;
        vector <int> a(n);
        int m = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            m = max (a[i], m);
        }
        sort(a.begin(), a.end());
        int x = m;
        int sz = n - 2;
        for (int i = 0; i < n - 1; i++) {
            set <int> nums;
            for (int j = 0; j < n - 1; j++) {
                if (j != i) {
                    nums.insert(a[j]);
                }
            }
            int curmax = *nums.begin();
        }
    }
}
