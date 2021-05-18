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
        vector <int> temp(n);
        iota (temp.begin(), temp.end(), 0);
        sort (temp.begin(), temp.end(), [&a](int x, int y) {
            return a[x].first < a[y].first;
        });
        vector <int> ans (n, -1);
        // store the indexes
        vector <int> st[2][2];
        // st[0][0] stores {left, even}, st[1][1] stores {right, odd}
        for (int i = 0; i < n; i++) {
            // get rid of left, first
            int p = a[temp[i]].first % 2;
            if (a[temp[i]].second == 'L') {
                if (st[1][p].size() == 0) {
                    st[0][p].push_back (temp[i]);
                    // debug(a[temp[i]].first);
                } else {
                    ans[temp[i]] = (abs (a[temp[i]].first - a[st[1][p][st[1][p].size()-1]].first)) / 2;
                    ans[st[1][p][st[1][p].size()-1]] = (abs (a[temp[i]].first - a[st[1][p][st[1][p].size()-1]].first)) / 2;
                    st[1][p].pop_back();
                }
            } else {
                st[1][p].push_back (temp[i]);
            }
        }
        // get rid of left and right that can still collide
        // collides with other stuff, right within its own stack
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (i == 0) reverse (st[i][j].begin(), st[i][j].end());
                while (st[i][j].size() >= 2) {
                    int sz = st[i][j].size();
                    if (i == 1) {
                        ans[st[i][j][sz-1]] = (m - a[st[i][j][sz-1]].first + m - a[st[i][j][sz-2]].first) / 2;
                        ans[st[i][j][sz-2]] = (m - a[st[i][j][sz-1]].first + m - a[st[i][j][sz-2]].first) / 2;
                        st[i][j].pop_back();
                        st[i][j].pop_back();
                    } else {
                        ans[st[i][j][sz-1]] = (a[st[i][j][sz-1]].first + a[st[i][j][sz-2]].first) / 2;
                        ans[st[i][j][sz-2]] = (a[st[i][j][sz-1]].first + a[st[i][j][sz-2]].first) / 2;
                        st[i][j].pop_back();
                        st[i][j].pop_back();
                    }
                }
            }
        }
        // for (int i = 0; i < (int) st[0][0].size(); i++) {
            // if (st[1][0].size() == 0) break;
            // ans[st[0][0][st[0][0].size()-1]] = (abs (a[st[0][0][st[0][0].size()-1]].first - a[st[1][0][st[1][0].size()-1]].first)) / 2;
            // st[1][0].pop_back();
        // }
        // for (int i = 0; i < (int) st[0][1].size(); i++) {
            // if (st[1][1].size() == 0) break;
            // ans[st[0][1][st[0][1].size()-1]] = (abs (a[st[0][1][st[0][1].size()-1]].first - a[st[1][1][st[1][1].size()-1]].first)) / 2;
            // st[1][1].pop_back();
        // }
        if (st[0][0].size() > 0 && st[1][0].size() > 0) {
            ans[st[0][0][0]] = (a[st[0][0][0]].first + m - a[st[1][0][0]].first + m) / 2;
            ans[st[1][0][0]] = (a[st[0][0][0]].first + m - a[st[1][0][0]].first + m) / 2;
        }
        if (st[0][1].size() > 0 && st[1][1].size() > 0) {
            ans[st[0][1][0]] = (a[st[0][1][0]].first + m - a[st[1][1][0]].first + m) / 2;
            ans[st[1][1][0]] = (a[st[0][1][0]].first + m - a[st[1][1][0]].first + m) / 2;
        }
        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
}
