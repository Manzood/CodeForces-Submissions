#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, q;
        scanf("%d%d", &n, &q);
        vector <int> a(n + 2);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        a[0] = 0;
        a[n+1] = 0;
        long long ans = 0;
        int prev = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > prev) {
                ans += a[i] - prev;
                prev = a[i];
            }
            else {
                prev = a[i];
            }
        }
        printf("%lld\n", ans);
        for (int i = 0; i < q; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            if (a[l] > a[l-1] && a[l] > a[l+1]) {
                int m = max (a[l-1], a[l+1]);
                ans -= a[l] - m;
            }
            if (a[l] < a[l-1] && a[l] < a[l+1] && r != l + 1) {
                int m = min(a[l-1], a[l+1]);
                ans -= m - a[l];
            }
            if (a[r] > a[r-1] && a[r] > a[r+1]) {
                int m = max (a[r-1], a[r+1]);
                ans -= a[r] - m;
            }
            if (a[r] < a[r-1] && a[r] < a[r+1] && r != l + 1) {
                int m = min(a[r-1], a[r+1]);
                ans -= m - a[r];
            }
            swap(a[l], a[r]);
            if (a[l] > a[l-1] && a[l] > a[l+1]) {
                int m = max (a[l-1], a[l+1]);
                ans += a[l] - m;
            }
            if (a[l] < a[l-1] && a[l] < a[l+1] && r != l + 1) {
                int m = min(a[l-1], a[l+1]);
                ans += m - a[l];
            }
            if (a[r] > a[r-1] && a[r] > a[r+1]) {
                int m = max (a[r-1], a[r+1]);
                ans += a[r] - m;
            }
            if (a[r] < a[r-1] && a[r] < a[r+1] && r != l + 1) {
                int m = min(a[r-1], a[r+1]);
                ans += m - a[r];
            }
            printf("%lld\n", ans);
        }
    }
}
