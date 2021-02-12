#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        int ans = 1e9+7;
        int s = 0;
        if (b == 1) {
            b++;
            s++;
        }
        bool flag = true;
        while (flag) {
            int temp = a;
            int cur = s;
            while (temp) {
                temp /= b;
                cur++;
            }
            if (cur > ans) break;
            ans = min(cur, ans);
            b++;
            s++;
        }
        printf("%lld\n", ans);
    }
}
