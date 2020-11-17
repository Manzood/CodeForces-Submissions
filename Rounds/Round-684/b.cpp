#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int N = n*k;
        vector <int> a(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        int step = n / 2;
        for (int i = N-1-step; i >= 0 && k > 0; i -= (step+1)) {
            ans += a[i];
            k--;
        }
        printf("%lld\n", ans);
    }
}