#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    cin >> n;
    int q = 1;
    cout << "? " << q << endl;
    vector <int> dist(n);
    vector <bool> marked(n, false);
    marked[0] = true;
    int oddcnt = 0;
    int evencnt = 0;
    vector <vector <int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
        if (dist[i] == 1) {
            adj[0].push_back (i);
        }
        if (dist[i] > 0) {
            if (dist[i] % 2 == 1) {
                oddcnt++;
            } else {
                evencnt++;
            }
        }
    }
    vector <int> temp(n);
    if (oddcnt < evencnt) {
        for (int i = 0; i < n; i++) {
            if (dist[i] % 2 == 1) {
                cout << "? " << i + 1 << endl;
                for (int j = 0; j < n; j++) {
                    cin >> temp[j];
                    if (temp[j] == 1 && !marked[j]) {
                        adj[i].push_back (j);
                    }
                }
                marked[i] = true;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] % 2 == 0 && dist[i] > 0) {
                cout << "? " << i + 1 << endl;
                for (int j = 0; j < n; j++) {
                    cin >> temp[j];
                    if (temp[j] == 1 && !marked[j]) {
                        adj[i].push_back (j);
                    }
                }
                marked[i] = true;
            }
        }
    }
    cout << "!" << endl;
    for (int i = 0; i < n; i++) {
        for (auto x: adj[i]) {
            cout << i + 1 << " " << x + 1 << endl;
        }
    }
}
