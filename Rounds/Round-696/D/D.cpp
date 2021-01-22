#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n; scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        bool possible = false;
        int x = -1;
        int y = -1;
        int val = a[0];
        for (int i = 1; i < n; i++) {
            val = a[i] - val;
            if (val < 0) {
                x = i;
                break;
            }
        }
        if (val == 0) possible = true;
        val = a[n-1];
        for (int i = n - 2; i >= 0; i--) {
            val = a[i] - val;
            if (val < 0) {
                y = i;
                break;
            }
        }
        debug(val);
        if (val == 0) possible = true;
        if (x == y || possible) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
