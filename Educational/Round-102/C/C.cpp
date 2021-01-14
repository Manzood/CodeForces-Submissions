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
        int diff = n - k;
        int okay = k - diff;
        int last = k;
        for (int i = 0; i < k; i++) {
            if (i < okay - 1) {
                printf("%lld ", i + 1);
            } else {
                printf("%lld ", last--);
            }
        }
        printf("\n");
    }
}
