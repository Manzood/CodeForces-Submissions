#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

bool is_prime (int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        scanf("%lld", &d);
        int f = d + 1;
        while (!is_prime(f)) {
            f++;
        }
        int sec = f + d;
        while (!is_prime(sec)) {
            sec++;
        }
        int ans = f * sec;
        printf("%lld\n", ans);
    }
}
