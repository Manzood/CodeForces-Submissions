#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int LOG = 20;
const int N = 3e5 + 5;

int32_t main() {
    // keep track of ancestors
    // efficiently find ancestors using binary lifting
    // keep track of children so as to be able to move downwards
    int q;
    vector <pair <int, int>> vertices(N);
    cin >> q >> vertices[0].first >> vertices[0].second;
    vector <vector <int>> ancestor(N);
    ancestor[0] = vector <int> (LOG, -1);
    // vector <int> child(N, -1);

    for (int i = 1; i <= q; i++) {
        int query; cin >> query;

        if (query == 1) {
            int p;
            cin >> p >> vertices[i].first >> vertices[i].second;
            // child[p] = i;
            ancestor[i] = vector <int> (LOG, -1);
            ancestor[i][0] = p;

            for (int j = 1; j < LOG; j++) {
                if (ancestor[i][j-1] >= 0) ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
            }

        } else {
            int v, w;
            cin >> v >> w;
            int original = v;
            int taken = 0;
            int cost = 0;

            while (taken < w && v != -1) {
                // debug (v);
                v = original;
                int k = LOG - 1;
                while (k >= 0) {
                    if (ancestor[v][k] >= 0 && vertices[ancestor[v][k]].first > 0) {
                        v = ancestor[v][k];
                    }
                    k--;
                }

                int rem = w - taken;
                taken += min (vertices[v].first, rem);
                cost += min (vertices[v].first, rem) * vertices[v].second;
                vertices[v].first = max (0LL, vertices[v].first - rem);
                if (v == original) break;
                // v = child[v];
            }

            printf("%lld %lld\n", taken, cost);
        }
    }
}
