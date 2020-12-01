#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        scanf("%lld%lld", &n, &x);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        bool possible = true;
        int ops = 0;
        for (int i = 0; i < n-1 && possible;) {
            bool changed = false;
            if (a[i] > a[i+1]) {
                if (a[i] <= x || (i > 0 && a[i] < a[i-1])) {
                    possible = false;
                } else {
                    int j = i;
                    if (a[i+1] < x) {
                        possible = false;
                        break;
                    }
                    swap(a[j], x);
                    ops++;
                    while (j > 0 && a[j] < a[j-1]) {
                        if (!(j > 1 && a[j-1] == a[j-2])) ops++;
                        swap(a[j], a[j-1]);
                        j--;
                    }
                    changed = true;
                }
            }
            if (!changed) i++;
        }
        for (int i = 0; i < n-1; i++) {
            if (a[i] > a[i+1]) possible = false;
        }
        possible ? printf("%lld\n", ops) : printf("-1\n");
    }
}
