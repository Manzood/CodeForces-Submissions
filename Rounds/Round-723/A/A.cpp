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
        vector <int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            scanf("%lld", &a[i]);
        }
        sort (a.begin(), a.end());
        vector <int> b;
        for (int i = 0; i < n; i++) {
            b.push_back (a[i]);
            b.push_back (a[i + n]);
        }
        for (int i = 0; i < 2 * n; i++) {
            printf("%lld ", b[i]);
        }
        printf("\n");
    }
}
