#include "bits/stdc++.h"
using namespace std;

int dfs (char cur, vector <char>& b, vector <string>& a, int len, int n) {
    int ans = 0;
    if (len == n) {
        return 1;
    }
    for (int i = 0; i < (int)b.size(); i++) {
        if (b[i] == cur) {
            ans += dfs (a[i][0], b, a, len+1, n);
        }
    }
    return ans;
}

int main() {
    int n; cin >> n;
    int q; cin >> q;
    char cur = 'a';
    vector <string> a(q);
    vector <char> b(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
    }
    int len = 1;
    int ans = 0;
    ans = dfs (cur, b, a, len, n);
    printf("%d", ans);
}
