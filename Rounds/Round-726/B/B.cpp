#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i, j;
        scanf("%lld%lld%lld%lld", &n, &m, &i, &j);
        int a[4];
        if (n - i + m - j + i + j - 2 > i - 1 + m - j + j - 1 + n - i) {
            a[0] = 1;
            a[1] = 1;
            a[2] = n;
            a[3] = m;
        } else {
            a[0] = 1;
            a[1] = m;
            a[2] = n;
            a[3] = 1;
        }
        printf("%lld %lld %lld %lld\n", a[0], a[1], a[2], a[3]);
    }
}
