#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
// finish this

bool isCounted (vector <int>& a, int i) {
    if (i > 0 && i < (int) a.size() - 1) {
        if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) {
            return true;
        }
    }
    return false;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n; scanf("%lld", &n);
        vector <int> a(n);
        int original = 0;

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 1; i < n - 1; i++) {
            if (isCounted(a, i)) {
                original++;
            }
        }

        int ans = original;
        for (int i = 1; i < n - 1; i++) {
            int temp = a[i];
            int x = ans;
            for (int j = i - 1; j < i + 2; j++) {
                if (isCounted(a, j)) {
                    x--;
                }
            }
            debug(x);
            if (a[i] < max(a[i-1], a[i+1])) {
                a[i] = min(a[i-1], a[i+1]);
            } else {
                a[i] = max(a[i-1], a[i+1]);
            }
            for (int j = i - 1; j < i + 2; j++) {
                if (isCounted(a, j)) {
                    x++;
                }
            }
            debug(x);
            ans = max(min(x, ans), 0LL);
            a[i] = temp;
        }
        printf("%lld\n", ans);
    }
}
