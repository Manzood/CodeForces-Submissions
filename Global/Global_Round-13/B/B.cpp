#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        scanf("%lld%lld%lld", &n, &u, &v);
        vector <int> a(n);
        bool f = false;
        bool s = false;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (i > 0) {
                if (abs(a[i] - a[i-1]) >= 2) {
                    f = true;
                } else if (abs(a[i] - a[i-1]) > 0) {
                    s = true;
                }
            }
        }
        if (f) printf("0\n");
        else if (s) printf("%lld\n", min(u, v));
        else printf("%lld\n", v + min(u, v));
    }
}
