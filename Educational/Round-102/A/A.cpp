#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        scanf("%lld%lld", &n, &d);
        vector <int> a(n);
        bool okay = true;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (a[i] > d) okay = false;
        }
        sort(a.begin(), a.end());
        if (a[0] + a[1] <= d) {
            okay = true;
        }
        if (okay) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
