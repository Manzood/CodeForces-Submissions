#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n; scanf("%lld", &n);
        vector <int> a(n);
        vector <int> p(n + 1);
        vector <int> s(n + 1);
        p[0] = 0;
        s[n] = 0;
        bool ans = false;
        bool was_zero = false;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            p[i + 1] = a[i] - p[i];
            if (p[i+1] < 0) was_zero = true;
            if (p[i] < 0) p[i+1] = -1;
        }
        if (p[n] == 0 && !was_zero) ans = true;
        for (int i = n - 1; i >= 0; i--) {
            s[i] = a[i] - s[i+1];
            if (s[i+1] < 0) s[i] = -1;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i+2] - a[i] + a[i+1] - p[i] == 0 && s[i+2] >= 0 && p[i] >= 0 && p[i] <= a[i+1] && a[i+1] - p[i] <= a[i]) {
                ans = true;
            }
        }
        printf(ans ? "YES\n" : "NO\n");
    }
}
