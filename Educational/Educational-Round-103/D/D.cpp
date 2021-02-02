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
        string s;
        cin >> s;
        vector <int> ans(n + 1, 1);
        for (int i = 0; i < n + 1; i++) {
            if (i < n) {
                if (s[i] == 'R') {
                    ans[i]++;
                }
            }
            if (i > 0) {
                if (s[i-1] == 'L') {
                    ans[i]++;
                    if (i > 1 && s[i-2] == 'R') {
                        ans[i] += ans[i-2] - 1;
                    }
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == 'R') {
                if (s[i+1] == 'L') {
                    ans[i] = ans[i+2];
                }
            }
        }
        for (int i = 0; i < n + 1; i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
}
