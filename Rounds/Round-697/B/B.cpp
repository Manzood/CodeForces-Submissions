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
        int x = n / 2020;
        if (n % 2020 <= x) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
