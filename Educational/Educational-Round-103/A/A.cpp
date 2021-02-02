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
        int add = 0;
        if (k < n) {
            if (n % k == 0) {
                k = n;
            } else {
                k = n + k - (n % k);
            }
        }
        if (k % n) add++;
        printf("%lld\n", max(1LL, k / n) + add);
    }
}
