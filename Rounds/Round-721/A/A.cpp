#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        int p = 1;
        while (p * 2 <= n) {
            p *= 2;
        }
        p--;
        printf("%lld\n", p);
    }
}
