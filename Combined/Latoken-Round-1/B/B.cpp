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
        vector <int> a(n);
        int ugliness = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        if (n > 1) {
            ugliness += a[0];
            ugliness += a[n-1];
            for (int i = 1; i < n; i++) {
                ugliness += abs (a[i] - a[i-1]);
            }
            if (n > 2) {
                for (int i = 1; i < n - 1; i++) {
                    if (a[i] > a[i-1] && a[i] > a[i+1]) {
                        int mx = max (a[i-1], a[i+1]);
                        ugliness -= a[i] - mx;
                    }
                }
                if (a[0] > a[1]) {
                    ugliness -= a[0] - a[1];
                }
                if (a[n-1] > a[n-2]) {
                    ugliness -= a[n-1] - a[n-2];
                }
            } else {
                ugliness -= abs (a[1] - a[0]);
            }
        } else {
            ugliness = a[0];
        }
        printf("%lld\n", ugliness);
    }
}
