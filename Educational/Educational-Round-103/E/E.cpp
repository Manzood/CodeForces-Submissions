#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    map <string, int> patterns;
    vector <string> s(m);
    vector <vector <int>> adj(n);
    vector <int> pos(n);
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        patterns[temp] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        scanf("%lld", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
    }
}
