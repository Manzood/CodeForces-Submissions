#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        vector <int> a(n);
        bool failed = false;
        int div = x; 
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            ans += a[i];
        }
        int i = 0;
        while (!failed) {
            if (a[i] % x != 0) {
                failed = true;
            } else {
                a.push_back(a[i] / x);
                ans += a[i % n];
            }
            i++;
            if (i == n) {
                div *= x;
            }
        }
        printf("%lld\n", ans);
    }
}