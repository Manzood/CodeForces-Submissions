#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c0, c1, h;
        scanf("%d%d%d%d", &n, &c0, &c1, &h);
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cnt++;
        }
        int ans = 0;
        if (c0 > c1 + h) {
            ans = (n-cnt) * (c1 + h);
            ans += cnt * c1;
        } else if (c1 > c0 + h) {
            ans = cnt * (c0 + h);
            ans += (n-cnt) * c0;
        } else {
            ans = cnt * c1;
            ans += (n-cnt) * c0;
        }
        printf("%d\n", ans);
    }
}