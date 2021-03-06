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
        vector <int> ans;
        for (int i = k / 2; i < k; i++) {
            if (k % 2 == 1 && i == k / 2) {
                continue;
            }
            ans.push_back(i);
        }
        for (int i = k + 1; i <= n; i++) {
            ans.push_back(i);
        }
        printf("%lld\n", (int)ans.size());
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
}
