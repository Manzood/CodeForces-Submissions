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
        while (n % 2 == 0) {
            n /= 2;
        }
        if (n > 1) printf("YES\n");
        else printf("NO\n");
    }
}
