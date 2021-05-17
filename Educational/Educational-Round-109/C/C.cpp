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
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i].first);
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i].second;
        }
        vector <int> temp;
        iota (temp.begin(), temp.end(), 0);
        sort (temp.begin(), temp.end(), [&a](int x, int y) {
            return a[x].first < a[y].first;
        });
        vector <int> ans (n, -1);
        vector <int> parity[2][2]; // parity[0][0] stores left, even, parity[0][1] stores left, odd
        for (int i = 0; i < n; i++) {
            // first make non-reflective comparisons
            int ind = temp[i];
            int p = a[i].first % 2;
            int l;
            if (a[ind].second == 'L') {
                l = 0;
                if ((int) parity[1][p].size() == 0) {
                    // add it to the stack
                    parity[0][p].push_back (a[temp[i]].first);
                } else {
                    // otherwise pop
                    // ans[temp[i]] = abs (parity[1][0].back() - );
                    int tempsize = parity[1][0].size();
                    ans[temp[1]] = abs (parity[1][0][tempsize-1] - a[temp[i]].first);
                    parity[1][0].pop_back();
                }
            } else {
                l = 1;
                // add it to the stack
                parity[1][0].push_back (a[temp[i]].first);
            }
        }
    }
}
