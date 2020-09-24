#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, q;
        scanf("%lld%lld", &n, &q);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        long long ans = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
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
            scanf("%lld%lld", &l, &r);
            l--; r--;
            if (((l > 0 && a[l] > a[l-1]) || l == 0) && ((l < n-1 && a[l] > a[l+1]) || l == n-1)) {
                int m = 0;
                if (l > 0) m = a[l-1];
                if (l < n-1) m = max(m, a[l+1]);
                ans -= a[l] - m;
            } 
            if (((l > 0 && a[l] < a[l-1]) || l == 0) && ((l < n-1 && a[l] < a[l+1]) || l == n-1)) {
                int m = n+1;
                if (l > 0) m = a[l-1];
                if (l < n-1) m = min(m, a[l+1]);
                if (m != n+1) {
                    ans -= m - a[l];
                }
            } 
            if (((r > 0 && a[r] > a[r-1]) || r == 0) && ((r < n-1 && a[r] > a[r+1]) || r == n-1)) {
                int m = 0;
                if (r > 0) m = a[r-1];
                if (r < n-1) m = max(m, a[r+1]);
                ans -= a[r] - m;
            } 
            if (((r > 0 && a[r] < a[r-1]) || r == 0) && ((r < n-1 && a[r] < a[r+1]) || r == n-1)) {
                int m = n+1;
                if (r > 0) m = a[r-1];
                if (r < n-1) m = min(m, a[r+1]);
                if (m != n+1) {
                    ans -= m - a[r];
                }
            } 
            swap (a[l], a[r]);
            if (((l > 0 && a[l] > a[l-1]) || l == 0) && ((l < n-1 && a[l] > a[l+1]) || l == n-1)) {
                int m = 0;
                if (l > 0) m = a[l-1];
                if (l < n-1) m = max(m, a[l+1]);
                ans += a[l] - m;
            } 
            if (((l > 0 && a[l] < a[l-1]) || l == 0) && ((l < n-1 && a[l] < a[l+1]) || l == n-1)) {
                int m = n+1;
                if (l > 0) m = a[l-1];
                if (l < n-1) m = min(m, a[l+1]);
                if (m != n+1) {
                    ans += m - a[l];
                }
            } 
            if (((r > 0 && a[r] > a[r-1]) || r == 0) && ((r < n-1 && a[r] > a[r+1]) || r == n-1)) {
                int m = 0;
                if (r > 0) m = a[r-1];
                if (r < n-1) m = max(m, a[r+1]);
                ans += a[r] - m;
            } 
            if (((r > 0 && a[r] < a[r-1]) || r == 0) && ((r < n-1 && a[r] < a[r+1]) || r == n-1)) {
                int m = n+1;
                if (r > 0) m = a[r-1];
                if (r < n-1) m = min(m, a[r+1]);
                if (m != n+1) {
                    ans += m - a[r];
                }
            } 
            if (l == r-1) {
                if (a[r] > a[l]) {
                    // hopefull I'll finish this soon
                }
            }
            printf("%lld\n", ans);
        }
    }
}