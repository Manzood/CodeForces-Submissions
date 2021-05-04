#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        scanf("%lld%lld%lld", &n, &m, &x);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        set <pair <int , int>> h;
        vector <int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i < m) {
                ans[i] = i;
                h.insert({a[i], i});
            } else {
                pair <int, int> it = *h.begin();
                h.erase (it);
                ans[i] = it.second;
                it.first += a[i];
                h.insert (it);
            }
        }
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i] + 1);
        }
        printf("\n");
    }
}
