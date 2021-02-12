#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        // find answer by dividing until x/y
        // then for each b until (b+1)*(b-1) > x, find count
        int x, y;
        scanf("%lld%lld", &x, &y);
        int ans = 0;
        int prev = x;
        for (int i = 2; i < y + 1; i++) {
            int coeff = i - 1;
            int temp = x / i;
            if (temp == 1) ans += x - 2;
            else ans += (max(0LL, min(prev, y) - temp + 1)) * coeff;
            prev = temp - 1;
        }
        for (int i = 2; (i + 1) * (i - 1) < x && i <= y; i++) {
            ans += i - 1;
        }
        printf("%lld\n", ans);
    }
}
