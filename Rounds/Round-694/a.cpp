#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        scanf("%lld%lld", &n, &x);
        long long sum = 0;
        int high = 0;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (a[i] % x) high++;
            high += a[i] / x;
            sum += a[i];
        }
        int low = sum / x;
        if (sum % x) low++;
        printf("%lld %lld\n", low, high);
    }
}