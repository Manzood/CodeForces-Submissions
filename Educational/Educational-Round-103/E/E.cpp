#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

bool check (string& p, string &s) {
    for (int i = 0; i < (int) s.size(); i++) {
        if (p[i] == '_') continue;
        if (p[i] != s[i]) return false;
    }
    return true;
}

int32_t main() {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector <string> patterns(n);
    vector <string> s(m);
    vector <vector <int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> patterns[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {

    }
}
