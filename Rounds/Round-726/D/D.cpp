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
        if (n & 1) {
            printf("Bob\n");
        } else {
            int p = 0;
            while (n % 2 == 0) {
                n /= 2;
                p++;
            }
            if (n > 1) {
                printf("Alice\n");
            } else {
                if (p % 2 == 0) {
                    printf("Alice\n");
                } else {
                    printf("Bob\n");
                }
            }
        }
    }
}
