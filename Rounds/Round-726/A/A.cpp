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
        int s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            s += a[i];
        }
        int ans = 0;
        if (s < n) {
            ans = 1;
        } else if (s > n) {
            ans = s - n;
        }
        printf("%lld\n", ans);
    }
}
