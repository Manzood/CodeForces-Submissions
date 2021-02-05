#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

// this is definitely a dp problem, so I should probably try the dp solution soon

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        vector <pair<int, int>> a(n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i].first);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i].second);
        vector <int> ones, twos;
        int onesum = 0, twosum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].second == 2) {
                twos.push_back(a[i].first);
                twosum += a[i].first;
            } else {
                ones.push_back(a[i].first);
            }
        }
        sort(ones.begin(), ones.end());
        sort(twos.begin(), twos.end());
    }
}
