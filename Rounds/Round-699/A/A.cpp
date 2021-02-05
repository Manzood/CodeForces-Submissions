#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        string s;
        cin >> s;
        int r = 0, u = 0, l = 0, d = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'R') r++;
            if (s[i] == 'L') l++;
            if (s[i] == 'D') d++;
            if (s[i] == 'U') u++;
        }
        int finx = r - l;
        int finy = u - d;
        bool ans = true;
        if (finx < x) {
            int val = x - finx;
            if (l < val) ans = false;
        } else if (finx > x) {
            int val = finx - x;
            if (r < val) ans = false;
        }
        if (finy < y) {
            int val = y - finy;
            if (d < val) ans = false;
        } else if (finy > y) {
            int val = finy - y;
            if (u < val) ans = false;
        }
        ans ? printf("YES\n") : printf("NO\n");
    }
}
