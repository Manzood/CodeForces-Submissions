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
        vector <int> mult;
        vector <int> not_mult;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (a[i] % 2 == 0) {
                mult.push_back (a[i]);
            } else {
                not_mult.push_back (a[i]);
            }
        }
        for (auto x: not_mult) {
            mult.push_back (x);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (__gcd (mult[i], 2 * mult[j]) > 1) {
                    ans++;
                }
            }
        }
        printf("%lld\n", ans);
    }
}
