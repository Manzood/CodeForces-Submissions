#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    set <int> divisors;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < min(15LL, n); i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                divisors.insert(j);
                divisors.insert(a[i] / j);
            }
        }
    }
    int ans = 0;
    set <int> used;
    for (auto x: divisors) {
        if (x <= ans) continue;
        int cnt = 0;
        for (int j = 0; j < min(n, 10000LL); j++) {
            int ind = rng() % n;
            if (n < 1000) {
                ind = j;
            }
            if (a[ind] % x == 0) cnt++;
        }
        if (cnt >= min(n / 2, 5000LL)) ans = max(x, ans);
    }
    printf("%lld\n", ans);
}
