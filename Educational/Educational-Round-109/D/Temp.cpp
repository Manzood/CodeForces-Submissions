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
    int s = 0;
    int p = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (s <= (i + 1 - p) / 2) {
            s = 2 * s - 1;
            ans += (s * (s - 1)) / 2 - max (((s - 1) * (s - 2)) / 2, 0LL);
            s = 0;
            p = i;
        }
    }
    printf("%lld\n", ans);
}
