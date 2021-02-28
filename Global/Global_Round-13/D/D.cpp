#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        int cnt = 0;
        bool unassigned = false;
        int totalu = 0;
        bool ans = true;
        for (int i = 32; i >= 0; i--) {
            if ((1LL << i) & v) {
                cnt++;
                if (!((1LL << i) & u)) {
                    unassigned = true;
                }
            }
            if ((1LL << i) & u) {
                totalu++;
                if (cnt > 0) {
                    cnt--;
                    totalu--;
                }
            }
            if (totalu && unassigned == false) {
                ans = false;
            }
        }
        if (cnt > 0) ans = false;
        if (totalu > 0 && !unassigned) ans = false;
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
}
