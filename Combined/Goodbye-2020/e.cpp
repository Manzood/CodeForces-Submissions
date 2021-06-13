#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long
const int mod = 1e9+7;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        vector <int> bitcount(64, 0);
        vector <int> rightres(n, 0);
        vector <int> newval(64, 0);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            for (int j = 0; j < 64; j++) {
                if (a[i] & (1LL << j)) {
                    bitcount[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 64; j++) {
                int cur = (1LL << j);
                if (a[i] & (1LL << j)) {
                    rightres[i] += (cur % mod) * n;
                } else {
                    rightres[i] += (cur % mod) * bitcount[j];
                }
                rightres[i] %= mod;
            }
        }
        for (int i = 0; i < 64; i++) {
            for (int j = 0; j < n; j++) {
                if (a[j] & (1LL << i)) {
                    newval[i] += rightres[j];
                    newval[i] %= mod;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int bit = 0; bit < 64; bit++) {
                int val = (1LL << bit);
                if (!(a[i] & val)) continue;
                ans += ((val % mod) * newval[bit]) % mod;
                ans %= mod;
            }
        }
        printf("%lld\n", ans);
    }
}