#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, q, k;
    scanf("%lld%lld%lld", &n, &q, &k);
    vector <int> a(n);
    vector <int> pref(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i == 0) pref[i] = a[i] - 1;
        else pref[i] = a[i] - a[i-1] - 1 + pref[i-1];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        l--; r--;
        int ans = 0;
        ans = pref[r] - pref[l];
        ans *= 2;
        ans += a[l] - 1;
        ans += k - a[r];
        printf("%lld\n", ans);
    }
}
