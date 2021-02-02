#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        vector <int> a(n);
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (i > 0) {
                if (sum * k < a[i] * 100) {
                    int add = 0;
                    if ((a[i] * 100 - sum * k) % k) {
                        add = 1;
                    }
                    ans += (a[i] * 100 - sum * k) / k;
                    sum += (a[i] * 100 - sum * k) / k;
                    ans += add;
                    sum += add;
                }
            }
            sum += a[i];
        }
        printf("%lld\n", ans);
    }
}
