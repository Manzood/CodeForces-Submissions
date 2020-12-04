#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        // take the difference between two numbers, not just one
        bool changed = false;
        int n;
        scanf("%d", &n);
        vector <int> a(n);
        int m = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i) m = max (m, abs(a[i] - a[i-1]));
        }
        long long ans = 0;
        for (int i = n-1; i >= 0; i--) {
            if (i && abs(a[i] - a[i-1]) == m && !changed) {
                a[i] = a[i-1];
                changed = true;
            } else if (i) {
                ans += abs (a[i] - a[i-1]);
            }
            debug(i);
            debug(ans);
        }
        printf("%lld\n", ans);
    }    
}
