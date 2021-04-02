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
        bool found = false;
        while (!found) {
            int temp = n;
            int sum = 0;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            if (__gcd(n, sum) > 1) found = true;
            else n++;
        }
        printf("%lld\n", n);
    }
}
