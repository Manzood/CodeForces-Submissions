#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld\n", &n);
        bool alice = false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if ((n / i) % 2 == 0) {
                    alice = true;
                }
                break;
            }
        }
        if (alice) {
            printf("Alice\n");
        } else {
            printf("Bob\n");
        }
    }
}
