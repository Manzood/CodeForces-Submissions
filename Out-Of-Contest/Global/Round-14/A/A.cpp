#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        scanf ("%lld%lld", &n, &x);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        sort (a.begin(), a.end());
        int sum = 0;
        bool possible = true;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum == x) {
                if (a[i] == a[n-1]) possible = false;
                else {
                    sum -= a[i];
                    swap (a[n-1], a[i]);
                    sum += a[i];
                }
            }
        }
        if (possible) {
            printf("YES\n");
            for (int i = 0; i < n; i++) {
                printf("%lld ", a[i]);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
}
