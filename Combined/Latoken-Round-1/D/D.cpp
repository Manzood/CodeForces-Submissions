#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    cin >> n;
    vector <bool> marked(n, false);
    vector <vector <int>> adj(n);
    int last = 0;
    int mx = -1;
    // find the ones with the least count, and mark those
    int found = 0;
    for (int i = 0; i < n && found < n - 1; i++) {
        if (last != -1) {
            marked[last] = true;
            cout << "? " << last + 1 << endl;;
            vector <int> l(n, -1);
            vector <int> cnt(n, 0);
            vector <int> dist(n);
            for (int j = 0; j < n; j++) {
                cin >> dist[j];
                if (!marked[j]) cnt[dist[j]]++;
                l[dist[j]] = j;
                if (dist[j] == 1 && !marked[j]) {
                    found++;
                    adj[last].push_back (j);
                }
            }
            int lastcnt = 1;
            int p = l[lastcnt];
            if (cnt[lastcnt] == 1) {
                for (int j = 0; j < n; j++) {
                    if (dist[j] == lastcnt + 1) {
                        found++;
                        adj[p].push_back (j);
                        marked[p] = true;
                    }
                }
                lastcnt++;
                p = l[lastcnt];
            }
            mx = 1e9 + 7;
            for (int j = 0; j < n; j++) {
                if (cnt[j] < mx) {
                    mx = cnt[j];
                    last = l[j] + 1;
                }
            }
        }
    }
    cout << "!" << endl;
    for (int i = 0; i < n; i++) {
        if ((int)adj[i].size() > 0) {
            for (int j = 0; j < (int) adj[i].size(); j++) {
                cout << i + 1 << " " << adj[i][j] + 1 << endl;
            }
        }
    }
}
