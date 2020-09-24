#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        // find highest set bit of each number and then check if that has already been found
        vector <int> cnt(32, 0);
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            long long num = 1LL;
            int highest = 0;
            for (int j = 0; j < 32; j++) {
                if (a[i] & num) {
                    highest = j;
                }
                num = num << 1;
            }
            cnt[highest]++;
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (cnt[i] > 0) {
                int temp = --cnt[i];
                ans += (temp*(temp+1))/2;
            }
        }
        printf("%lld\n", ans);
    }
}