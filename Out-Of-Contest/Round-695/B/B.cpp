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
        vector <bool> check(n, false);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        bool found = false;
        bool three = false;
        int count = 0;
        vector <bool> hill(n, false);
        for (int i = 1; i < n - 1; i++) {
            if ((a[i-1] > a[i] && a[i+1] > a[i]) || (a[i-1] < a[i] && a[i+1] < a[i])) {
                if (a[i] > a[i-1] && a[i] > a[i+1]) hill[i] = true;
                check[i] = true;
                count++;
            }
            if (i > 1 && check[i] && check[i-2] && hill[i] == hill[i-2]) {
                found = true;
                if (check[i-1]) three = true;
            } else if (i > 0 && check[i] && check[i-1]) {
                found = true;
            }
        }
        if (three) {
            printf("%lld\n", count - 3);
        } else if (found) {
            printf("%lld\n", count - 2);
        } else {
            printf("%lld\n", max(count - 1, 0LL));
        }
    }
}
