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
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        map <int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += mp[a[i]] * (n - i);
            mp[a[i]] += i + 1;
        }
        printf("%lld\n", ans);
    }
}
