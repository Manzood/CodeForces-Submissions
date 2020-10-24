#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long
vector <vector <int>> adj;
vector <int> cnt;

int dfs (int node) {
    if ((int)adj[node].size() == 0) return cnt[node];
    for (auto u: adj[node]) {
        cnt[node] += dfs(u);
    }
    return cnt[node];
}

int32_t main() {
    int n; scanf("%lld", &n);
    adj.resize(n);
    cnt.resize(n);
    vector <int> count(n);
    for (int i = 1; i < n; i++) {
        int u; scanf("%lld", &u);
        u--; 
        adj[u].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &count[i]);
        cnt[i] = count[i];
    }
    int current = 0;
    dfs(0);
    for (int i = 0; i < n; i++) {
        debug(cnt[i]);
    }
    while ((int)adj[current].size() > 0) {
        int temp = adj[current].size();
        int m = cnt[adj[current][0]];
        int mincity = adj[current][0];
        int maxcity = adj[current][0];
        int maxvar = cnt[adj[current][0]];
        for (int i = 0; i < temp; i++) {
            if (cnt[adj[current][i]] < m) {
                mincity = adj[current][i];
                m = cnt[adj[current][i]];
            }
            if (cnt[adj[current][i]] > maxvar) {
                maxcity = adj[current][i];
                maxvar = cnt[adj[current][i]];
            }
        }
        cnt[mincity] += count[current] / temp;
        if (mincity != maxcity) cnt[maxcity] += count[current] / temp;
        if (cnt[current] % temp != 0) cnt[mincity]++;
        if (cnt[mincity] > cnt[maxcity]) current = mincity;
        else current = maxcity;
    }
    printf("%lld\n", cnt[current]);
}