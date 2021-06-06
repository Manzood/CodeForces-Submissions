#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int LOG = 19;

void build (vector <vector <int>>& lift, int node) {
    for (int i = 1; i < LOG; i++) {
        lift[node][i] = lift[lift[node][i-1]][i-1];
    }
}

int32_t main() {
    // switching to cin and cout
    vector <vector <int>> lift;
    vector <pair <int, int>> vertices;
    vector <int> child;
    int q;
    cin >> q;
    int a, c;
    cin >> a >> c;
    vertices.push_back ({a, c});
    lift.push_back (vector <int> (LOG, 0));
    vector <int> get_vertex;
    get_vertex.push_back (0);
    child.push_back (-1);
    int pos = 0;
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            lift.push_back (vector <int> (LOG, 0));
            pos++;
            int p;
            cin >> p;
            p = get_vertex[p];
            lift[pos][0] = p;
            cin >> a >> c;
            build (lift, pos);
            vertices.push_back ({a, c});
            child.push_back (-1);
            child[p] = lift.size()-1;
            get_vertex.push_back (lift.size() - 1);
        } else {
            int v, w;
            cin >> v >> w;
            v = get_vertex [v];
            // find deepest nonzero ancestor
            int jump = LOG - 1;
            int original = v;
            while (jump >= 0) {
                if (vertices[lift[v][jump]].first > 0) {
                    v = lift[v][jump];
                }
                jump--;
            }
            int sum = 0;
            int cost = 0;
            while (sum < w && v != -1) {
                int rem = w - sum;
                sum += min (vertices[v].first, rem);
                cost += min (vertices[v].first, rem) * vertices[v].second;
                vertices[v].first = max (0LL, vertices[v].first - rem);
                if (v == original) break;
                if (vertices[v].first == 0) v = child[v];
            }
            cout << sum << " " << cost << endl;
            get_vertex.push_back (-1);
        }
    }
}
