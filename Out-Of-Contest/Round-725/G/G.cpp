#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
        if (x < y) swap (x, y);
        if (a < b) swap (a, b);
        int ans = 0;
        if (a != b) {
            int mult = (x - y) / (a - b);
            // int diff = (x - y) % (a - b);
            mult = min (mult, x / a);
            mult = min (mult, y / b);
            x -= a * mult;
            y -= b * mult;
            ans += mult;
            if (x >= a && y >= b) {
                if (abs((x - a - y + b)) < abs (x - y)) {
                    ans++;
                    x -= a;
                    y -= b;
                }
                int n = a + b;
                int mi = min (x, y);
                mult = mi / n;
                ans += mult * 2;
                x -= n * mult;
                y -= n * mult;
                if (x < y) swap (x, y);
                if (x >= a && y >= b) ans++;
            }
        } else {
            int mi = min (x, y);
            ans = mi / a;
        }
        printf("%lld\n", ans);
    }
}
