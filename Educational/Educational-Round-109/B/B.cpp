#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        bool is_sorted = true, f = false, s = false;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                if (a[i] == i + 1) {
                    f = true;
                }
            }
            if (a[i] != i + 1) is_sorted = false;
        }
        if (a[0] == n && a[n-1] == 1) {
            s = true;
        }
        if (is_sorted) {
            printf("0\n");
        } else if (s) {
            printf("3\n");
        } else if (f) {
            printf("1\n");
        } else {
            printf("2\n");
        }
    }
}
