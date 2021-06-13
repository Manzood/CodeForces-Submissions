#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int mod = 1e9 + 7;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        vector <int> b(n);
        vector <int> m1(n);
        vector <int> m2(n);
        vector <bool> marked (n, false);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            m1[a[i]-1] = i;
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &b[i]);
            m2[b[i]-1] = i;
        }
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                int start = a[i];
                int pos = i;
                while (b[pos] != start) {
                    marked[pos] = true;
                    pos = m1[b[pos]-1];
                }
                marked[pos] = true;
                cycles++;
            }
        }
        int ans = 1;
        for (int i = 0; i < cycles; i++) {
            ans *= 2;
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
}
