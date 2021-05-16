#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int inf = 1e9+7;

int32_t main() {
    // each 0 should be filled by an *available* 1 close to it
    // count deficiency of zeroes
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    vector <int> zeroes;
    vector <int> sum(n);
    int onescnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 1) onescnt++;
        if (i == 0) sum[i] = a[i];
        else sum[i] += sum[i-1] + a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            int cur = inf;
            // go left
            int zcnt = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] == 0) {
                    zcnt++;
                } else {
                    if (zcnt == 0) {
                        cur = min (cur, i - j);
                        break;
                    } else {
                        zcnt--;
                    }
                }
            }
            // go right
            // debug (i);
            // debug (sum[n-1] - sum[i]);
            zcnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] == 0) {
                    zcnt++;
                } else {
                    if (zcnt == 0) {
                        cur = min (cur, j - i);
                        break;
                    } else {
                        zcnt--;
                    }
                }
            }
            debug(cur);
            zeroes.push_back (cur);
        }
    }
    int ans = 0;
    sort (zeroes.begin(), zeroes.end());
    for (int i = 0; i < onescnt; i++) {
        ans += zeroes[i];
    }
    printf("%lld\n", ans);
}
