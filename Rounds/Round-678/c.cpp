#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long
const int mod = 1e9+7;

int32_t main() {
    int n, x, pos;
    scanf("%lld%lld%lld", &n, &x, &pos);
    int remaining = n;
    bool flag = true;
    long long ans = 1;
    int numgreater = n-x;
    int numless = x-1;
    int left = 0, right = n;
    int mid = (left + right) / 2;
    while (flag && left < right) {
        mid = (left + right) / 2;
        if (pos > mid) {
            ans *= numless;
            numless--;
            left = mid + 1;
        }
        else if (pos < mid) {
            ans *= numgreater;
            numgreater--;
            right = mid;
        }
        else {
            flag = false;
        }
        ans %= mod;
        if (ans == 0) {
            flag = false;
            break;
        }
        remaining--;
    }
    for (int i = remaining; i > 1; i--) {
        ans *= i;
        ans %= mod;
    }
    printf("%lld\n", ans);
}
