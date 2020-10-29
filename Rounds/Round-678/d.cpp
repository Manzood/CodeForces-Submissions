#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long

vector <vector <int>> adj;
vector <int> val;
vector <int> required;
vector <int> cnt;
vector <int> leaves;

int dfs1(int node) {
    // first you find the maximum value, then you can calculate the required value
    // val stores the maximum possible values of any leaves in the subtree
    if (adj[node].size() == 0) {
        leaves[node] = 1;
        val[node] = cnt[node];
        required[node] = 0;
        return 1;
    }
    int l = 0;
    val[node] = 0;
    for (auto x: adj[node]) {
        l += dfs1(x);
        // now that the dfs is done, the value should be set
        val[node] = max(val[node], val[x]);
    }
    leaves[node] = l;
    // doing it after because I have not found the maximum yet
    for (auto x: adj[node]) {
        required[node] += required[x];
        required[node] += (val[node] - val[x]) * leaves[x];
    }
    int m = min(required[node], cnt[node]);
    cnt[node] -= m; required[node] -= m;
    val[node] += cnt[node] / leaves[node]; 
    cnt[node] %= leaves[node];
    if (cnt[node]) required[node] += leaves[node] - cnt[node];
    val[node] += (cnt[node] % leaves[node]) ? 1 : 0;
    return l;
}

int32_t main() {
    // requirements: write a good, high quality dfs 
    // find remaining, keep track of maximum value to reach... this is the value to minimise, and therefore why dp will be so useful for this
    // since I'm terrible at dp, I'll have to find my own haphazard way of solving the problem
    // dfs 1: find the number of leaves for each node, 
    // still in dfs 1, it may be possible to backtrack and find the (minimum of) maxinum value for each while keeping track of required
    // since it's a tree that only points in one direction, there is no need to keep track of what nodes we've visited
    int n;
    cin >> n;
    cnt.resize(n);
    val.resize(n);
    required.resize(n);
    adj.resize(n);
    leaves.resize(n);
    for (int i = 1; i < n; i++) {
        int u; scanf("%lld", &u); u--;
        adj[u].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &cnt[i]);
    }
    dfs1(0);
    printf("%lld\n", val[0]);
}