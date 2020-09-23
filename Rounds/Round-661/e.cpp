#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long

vector <vector <pair<int, int>>> adj;
vector <int> w;
vector <int> cnt;
vector <bool> visited;

int dfs (int node, int edge) {
    if (visited[node]) return cnt[edge];
    visited[node] = true;
    if (adj[node].size() == 1 && node != 0) {
        cnt[edge] = 1;
        return 1;
    }
    int ans = 0;
    for (auto u: adj[node]) {
        if (u.second == edge) continue;
        int temp = dfs(u.first, u.second);
        ans += temp;
        if (temp > 0) cnt[u.second] = temp;
    }
    return ans;
} 

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        // Alright, for some clarity, make sure to store the edge number with the node
        // Also, store the weights alongside the edge number; don't forget to store the counts
        int n, s;
        scanf("%lld%lld", &n, &s);
        w = cnt = vector <int> (n-1);
        adj = vector <vector <pair <int, int>>> (n);
        visited = vector <bool> (n, false);
        for (int i = 0; i < n-1; i++) {
            int u, v;
            scanf("%lld%lld%lld", &u, &v, &w[i]);
            u--; v--;
            adj[u].push_back(make_pair (v, i));
            adj[v].push_back(make_pair(u, i));
        }
        dfs(0, -1); 
        vector <pair<int, int>> final(n-1);
        vector <pair<int, int>> diff (n-1);
        int sum = 0;
        for (int i = 0; i < n-1; i++) {
            final[i].first = w[i] * cnt[i];
            sum += final[i].first;
            final[i].second = cnt[i];
            diff[i].first = w[i] * cnt[i] - (w[i]/2) * cnt[i];
            diff[i].second = i;
        }
        make_heap(final.begin(), final.end());
        make_heap(diff.begin(), diff.end());
        int moves = 0;
        // debug(sum);
        while (sum > s) {
            // int temp;
            // pair <int, int> t1 = final.front();
            int t2 = diff.front().first;
            sum -= t2;
            int ind = diff.front().second;
            w[ind] /= 2;
            pop_heap(diff.begin(), diff.end());
            diff.pop_back();
            diff.push_back({w[ind] * cnt[ind] - (w[ind]/2) * cnt[ind], ind});
            push_heap(diff.begin(), diff.end());
            // temp = t1.first / t1.second;
            // sum -= t1.first;
            // temp /= 2;
            // sum += temp * t1.second;
            // t1.first = temp * t1.second;
            // pop_heap(final.begin(), final.end());
            // final.pop_back();
            // final.push_back(t1);
            // push_heap(final.begin(), final.end());
            moves++;
        }
        printf("%lld\n", moves);
    }
}   
