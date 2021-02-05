#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        int pos = -1;
        for (int i = 0; i < k; i++) {
            int temp = -1;
            for (int j = 0; j < n - 1; j++) {
                if (a[j+1] > a[j]) {
                    pos = j + 1;
                    temp = j + 1;
                    a[j]++;
                    break;
                }
            }
            if (temp == -1) {
                pos = -1;
                break;
            }
        }
        printf("%lld\n", pos);
    }
}
