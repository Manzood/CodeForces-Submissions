#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int mod = (int) 1e9 + 7;

vector <bool> visited;
void dfs (int node, vector <vector <int>>& adj) {
    if (visited[node]) return;
    visited[node] = true;
    for (auto u: adj[node]) {
        dfs (u, adj);
    }
}

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        visited.assign (n, false);
        vector <int> a(n), b(n);
        vector <vector <int>> adj(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &b[i]);
            adj[a[i]-1].push_back (b[i]-1);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs (i, adj);
                cnt++;
            }
        }
        int ans = 1;
        for (int i = 0; i < cnt; i++) {
            ans *= 2;
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
}
