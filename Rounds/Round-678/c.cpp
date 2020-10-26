#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long
const int mod = 1e9+7;

// this is currently an incorrect soln
int32_t main() {
    int n, x, pos;
    scanf("%lld%lld%lld", &n, &x, &pos);
    int remaining = n;
    long long ans = 1;
    int numgreater = n-x;
    int numless = x-1;
    int left = 0, right = n;
    int mid = (left + right) / 2;
    vector <int> calc(n, -1);
    bool found = false;
    while (left < right) {
        mid = (left + right) / 2;
        if (mid < pos) {
            if (!found) calc[mid-1] = numgreater;
            left = mid+1;
        } else if (mid > pos) {
            if (!found) calc[mid-1] = numless;
            right = mid;
        } else {
            calc[mid-1] = 1;
            left = mid+1;
            found = true;
            remaining--;
        }
        if (!found) remaining--;
    }
    if (!(left > 0 && left - 1 == pos))
        ans = 0;
    for (int i = 0; i < n; i++) {
        if (calc[i] == -1) {
            ans *= remaining--;
        } else {
            ans *= calc[i];
        }
        ans %= mod;
    }
    printf("%lld\n", ans);
}
