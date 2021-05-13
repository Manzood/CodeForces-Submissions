#include"bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        // move to the closest odd multiple of k
        int ans = 0;
        if (k > 0) {
            ans += n % k;
            n -= n % k;
            if ((n / k) % 2 != 1) {
                ans = k - ans;
                n += k;
                // ans += k;
            }
        } else {
            if (n % 2 == 1) {
                ans++;
            }
        }
        printf("%lld\n", ans);
    }
}
