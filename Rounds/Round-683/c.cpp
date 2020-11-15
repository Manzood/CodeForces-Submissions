#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, w;
        scanf("%lld%lld", &n, &w);
        vector <pair<int, int>> a(n);
        int ans = -1;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i].first);
            a[i].second = i;
            if (a[i].first >= (w/2) + (w&1) && a[i].first <= w) ans = a[i].second;
        }
        if (ans > -1) {
            printf("1\n%lld\n", ans+1);
        } else {
            sort(a.begin(), a.end());
            int index = -1;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i].first;
                if (sum > w) break;
                index = i;
            }
            sum = 0;
            int startindex = index;
            bool found = false;
            for (int i = index; i >= 0; i--) {
                startindex = i;
                sum += a[i].first;
                if (sum >= w/2+(w&1)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                printf("%lld\n", index - startindex + 1);
                for (int i = startindex; i <= index; i++) {
                    printf("%lld ", a[i].second + 1);
                }
                printf("\n");
            } else {
                printf("-1\n");
            }
        }
    }
}