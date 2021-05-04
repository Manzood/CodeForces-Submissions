#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

bool is_square (int n) {
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) return true;
    }
    return false;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        if ((n % 2 == 0 && is_square (n / 2)) || (n % 4 == 0 && is_square (n / 4))) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
