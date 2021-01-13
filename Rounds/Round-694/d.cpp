#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

long long factorize (int num) {
    int p = 2;
    int retval = 1;
    while (p * p <= num) {
        int cnt = 0;
        while (num % p == 0) {
            cnt++;
            num /= p;
        }
        cnt %= 2;
        if (cnt) retval *= p;
        if (p % 2 == 0) p++;
        else p += 2;
    }
    if (num) {
        retval *= num;
    }
    return retval;
}

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n; scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            a[i] = factorize(a[i]);
        }
        sort (a.begin(), a.end());
        int initial = 1;
        int cnt = 1;
        int fin = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]) {
                cnt++;
            } else {
                if (cnt % 2 == 0 || a[i-1] == 1) {
                    fin += cnt;
                }
                cnt = 1;
            }
            if (i == n-1) {
                if (cnt % 2 == 0 || a[i] == 1) {
                    fin += cnt;
                }
            }
            initial = max(cnt, initial);
        }
        fin = max(initial, fin);
        int q; scanf("%lld", &q);
        for (int i = 0; i < q; i++) {
            int w; scanf("%lld", &w);
            if (w == 0) {
                printf("%lld\n", initial);
            } else {
                printf("%lld\n", fin);
            }
        }
    }
}
