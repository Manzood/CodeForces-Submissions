#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int INF = 1e9+7;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector <int> a(n), b(n);
        int ma = INF;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            ma = min(a[i], ma);
        }
        int mb = INF;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            mb = min(b[i], mb);
        }
        int first = max (ma, mb);
        for (int i = 0; i < n; i++) {
            int temp = min (a[i] - ma, b[i] - mb);
            ans += a[i] - ma + b[i] - mb;
            ans -= temp;
        }
        printf("%lld\n", ans);
    }
}