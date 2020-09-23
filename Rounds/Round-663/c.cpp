#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long
const int MOD = 1e9+7;

int32_t main() {
    int n;
    scanf("%lld", &n);
    int ans = 1;
    int twopow = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        ans %= MOD;
        if (i > 1) twopow *= 2LL;
        twopow %= MOD;
    }
    ans -= twopow;
    if (ans < 0) ans += MOD;
    printf("%lld\n", ans);
}