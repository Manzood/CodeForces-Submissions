#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        vector <pair<int, int>> a(n);
        vector <int> t1;
        vector <int> t2;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i].first);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i].second);
        }
        for (int i = 0; i < n; i++) {
            if (a[i].second == 1) {
                t1.push_back(a[i].first);
            } else {
                t2.push_back(a[i].first);
                // debug(a[i].first);
            }
        }
        sort(t1.begin(), t1.end());
        int t_size = t1.size();
        int smallest = 0;
        if (t_size) smallest = t1[0];
        for (int i = t_size - 1; i - 1 >= 0; i -= 2) {
            t2.push_back(t1[i] + t1[i - 1]);
        }
        int remaining = 0;
        if (t_size & 1) {
            remaining = t1[0];
        }
        sort(t2.begin(), t2.end());
        int x = t2.size();
        int ans = 0;
        int sum = 0;
        // for (int i = 0; i < x; i++) {
            // debug(t2[i]);
        // }
        for (int i = x - 1; i >= 0 && sum < m; i--) {
            sum += t2[i];
            ans += 2;
            // debug(sum);
            if (sum >= m) break;
            if (sum + remaining >= m) {
                sum += remaining;
                ans++;
                break;
            }
        }
        if (t_size) {
            if (sum - smallest >= m) {
                ans--;
            }
        }
        if (sum < m) {
            ans = -1;
        }
        printf("%lld\n", ans);
    }
}
