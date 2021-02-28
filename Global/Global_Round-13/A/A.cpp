#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector <int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 1) cnt++;
    }
    for (int i = 0; i < q; i++) {
        int tt; scanf("%lld", &tt);
        if (tt == 1) {
            int x; scanf("%lld", &x);
            if (a[x-1] == 1) cnt--;
            else cnt++;
            a[x-1] ^= 1;
        } else {
            int k; scanf("%lld", &k);
            if (k <= cnt) printf("1\n");
            else printf("0\n");
        }
    }
}
