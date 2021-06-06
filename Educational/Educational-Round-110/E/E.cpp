#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int LOG = 20;

int32_t main() {
    // keep track of ancestors
    // efficiently find ancestors using binary lifting
    // keep track of children so as to be able to move downwards
    // keep track of each node. The question uses weird numbering
    int q, a0, c0;
    cin >> q >> a0 >> c0;
    vector <vector <int>> ancestor;
    ancestor.push_back (vector <int> (LOG, 0));
    vector <pair <int, int>> vertices = {{a0, c0}};
    vector <int> vertex = {0};
    vector <int> child = {-1};
    for (int i = 1; i <= q; i++) {
        vertex.push_back (-1);
        int query; cin >> query;
        if (query == 1) {
            int p, a, c;
            cin >> p >> a >> c;
            p = vertex[p];
            int v = vertices.size();
            vertices.push_back ({a, c});
            vertex[i] = vertices.size() - 1;
            child[p] = v;
            child.push_back (-1);
            ancestor.push_back (vector <int> (LOG, 0));
            ancestor[v][0] = p;
            for (int j = 1; j < LOG; j++) {
                ancestor[v][j] = ancestor[ancestor[v][j-1]][j-1];
            }
        } else {
            int v, w;
            cin >> v >> w;
            v = vertex[v];
            int original = v;
            // find the highest ancestor above v;
            int k = LOG - 1;
            while (k >= 0) {
                if (vertices[ancestor[v][k]].first > 0) {
                    v = ancestor[v][k];
                }
                k--;
            }
            int taken = 0;
            int cost = 0;
            while (taken < w && v != -1) {
                // debug (v);
                int rem = w - taken;
                taken += min (vertices[v].first, rem);
                // cost is wrong??
                cost += min (vertices[v].first, rem) * vertices[v].second;
                vertices[v].first = max (0LL, vertices[v].first - rem);
                if (v == original) break;
                v = child[v];
            }
            printf("%lld %lld\n", taken, cost);
        }
    }
}
