#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        scanf("%lld", &x);
        if (x >= 1100) {
            printf("YES\n");
        } else {
            bool possible = false;
            for (int i = 0; i <= 10; i++) {
                int val = 111 * i;
                int temp = x - val;
                if (temp < 0) continue;
                if (temp % 11 == 0) possible = true;
            }
            if (possible) printf ("YES\n");
            else printf("NO\n");
        }
    }
}
