#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        scanf("%lld", &k);
        int temp = k;
        int ans = 0;
        while (k % 100 != 0) {
            k += temp;
            ans++;
        }
        ans++;
        printf("%lld\n", ans);
    }
}
