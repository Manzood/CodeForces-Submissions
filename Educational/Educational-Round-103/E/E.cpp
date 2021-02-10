#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <int> answer;
vector <bool> visited;
vector <bool> processing;
bool ans = true;

void toposort (vector <vector <int>>& adj, int node) {
    if (visited[node]) return;
    visited[node] = true;
    processing[node] = true;
    for (auto x: adj[node]) {
        if (processing[x]) {
            ans = false; // back edge detected
        }
        toposort(adj, x);
    }
    processing[node] = false;
    answer.push_back(node);
}

int32_t main() {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    map <string, int> patterns;
    vector <string> s(m);
    vector <vector <int>> adj(n);
    vector <int> pos(m);
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        patterns[temp] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        scanf("%lld", &pos[i]);
    }
    for (int i = 0; i < m && ans; i++) {
        bool found = false;
        for (int j = 0; j < (1 << k); j++) {
            string temp;
            for (int x = 0; x < k; x++) {
                if ((1 << x) & j) {
                    temp += '_';
                } else {
                    temp += s[i][x];
                }
            }
            if (patterns[temp]) {
                if (patterns[temp] == pos[i]) found = true;
                else adj[pos[i] - 1].push_back(patterns[temp] - 1);
            }
        }
        if (!found) ans = false;
    }
    // toposort & detect cycles
    visited.resize(n, false);
    processing.resize(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) toposort(adj, i);
    }
    if (ans) {
        printf("YES\n");
        assert ((int)answer.size() == n);
        for (int i = n - 1; i >= 0; i--) {
            printf("%lld ", answer[i] + 1);
        }
    } else {
        printf("NO\n");
    }
}
