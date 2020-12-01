#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
// cleaner solution

bool check (vector <int>& a) {
    for (int i = 0; i < (int)a.size()-1; i++) {
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        bool is_sorted = check(a);
        int cur = 0;
        int ans = 0;
        if (!is_sorted) {
            for (int i = 0; i < n-1; i++) {
                if (a[i] > a[i+1]) ans = cur+1;
                if (a[i] > x) {
                    swap (a[i], x);
                    cur++;
                }
            }
        }
        is_sorted = check(a);
        !is_sorted ? printf("-1\n") : printf("%d\n", ans);
    }
}
