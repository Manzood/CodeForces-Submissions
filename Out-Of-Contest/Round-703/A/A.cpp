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
        int sum = 0;
        int req = 0;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            sum += a[i];
            req += i;
            if (sum < req) ans = false;
        }
        printf(ans ? "YES\n" : "NO\n");
    }
}
