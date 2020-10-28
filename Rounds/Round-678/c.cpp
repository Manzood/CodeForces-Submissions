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
    int ans = 1;
    int numgreater = n-x;
    int numless = x-1;
    int left = 0;
    int right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (mid < pos) {
            ans *= numless--;
            left = mid+1;
        } else if (mid > pos) {
            ans *= numgreater--;
            right = mid;
        } else {
            left = mid+1; 
        }
        remaining--;
        ans %= mod;
    }
    for (int i = remaining; i > 0; i--) {
        ans *= i;
        ans %= mod;
    }
    printf("%lld\n", ans);
}
