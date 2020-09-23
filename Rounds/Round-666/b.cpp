#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long
const long long MX = 1e16;

int32_t main() {
    int t = 1;
// cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a.begin(), a.end());
        int curr = 1;
        int mult = 1;
        int ans = MX;
        while (curr < (int)1e15) {
            curr = 1;
            int temp = 0;
            for (int i = 0; i < n; i++) {
                temp += abs(a[i] - curr);
                curr *= mult;
                if (curr > (int)1e15) break;
            }
            mult++;
            ans = min(ans, temp);
        }
        printf("%lld", ans);
    }
}