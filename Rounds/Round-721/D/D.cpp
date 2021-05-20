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
        vector <vector <int>> tree(n);
        // find total number of paths
        // keep adding to answer as you switch current node
        // once you reach a certain node, subtract from total available nodes
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%lld%lld", &u, &v);
            tree[u].push_back (v);
        }
    }
}
