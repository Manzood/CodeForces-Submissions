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
        vector <pair <int, char>> a(n);
        vector <pair <int, int>> even;
        vector <pair <int, int>> odd;
        vector <int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i].first);
        }
        char c;
        for (int i = 0; i < n; i++) {
            cin >> c;
            a[i].second = c;
        }
        for (int i = 0; i < n; i++) {
            if (a[i].first % 2 == 0) {
                even.push_back(a[i]);
            } else {
                odd.push_back (a[i]);
            }
        }
        sort (even.begin(), even.end());
        sort (odd.begin(), odd.end());
        // check for right-left collisions
        vector <int> p;
        for (int i = 0; i < n; i++) {
            if (a[i].second == 'R') {
                p.push_back (i);
            } else {
                if (p.size()) {
                    int ind = p[p.size() - 1];
                }
            }
        }
    }
}
