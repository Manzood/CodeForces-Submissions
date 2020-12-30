#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> w(n);
        vector <vector <int>> adj(n);
        vector <int> hp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &w[i]);
            ans += w[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v; scanf("%lld%lld", &u, &v); u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            if (adj[u].size() > 1) hp.push_back(w[u]);
            if (adj[v].size() > 1) hp.push_back(w[v]);
        }
        make_heap(hp.begin(), hp.end()); 
        for (int i = 1; i < n; i++) {
            printf("%lld ", ans);
            if ((int)hp.size()) ans += hp[0];
            else continue;
            pop_heap(hp.begin(), hp.end());
            hp.pop_back();
        }
        printf("\n");
    }
}