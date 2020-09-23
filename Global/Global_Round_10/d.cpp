#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        string s; cin >> s;
        // if there are three R's or three L's in a row, change it
        int count = 0;
        while (s[0] == s.back() && sz(s) > 0) {
            s.pop_back();
            count++;
        }
        int ans = 0;
        if (sz(s) == 0) {
            ans += count/3;
            if (count % 3 > 0) ans++;
            printf("%d\n", ans);
            continue;
        }
        for (int i = 0; i < sz(s); i++) {
            int j = i-1;
            if (j == -1) j = sz(s) - 1;
            if (s[i] == s[j] || (s[i] != s[j] && i == 0 && count > 0)) {
                count++;
            }
            else {
                ans += count/3;
                count = 1;
            }
        }
        ans += count/3;
        printf("%d\n", ans);
    }
}