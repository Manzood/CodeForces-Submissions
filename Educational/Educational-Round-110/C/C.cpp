#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int p = s[0] - '0';
        int ans = 1;
        int len = 1;
        int pos = -1;
        if (s[0] != '?') pos = 0;
        for (int i = 1; i < (int) s.size(); i++) {
            if (s[i] == '?') {
                p = '?';
                len++;
            } else {
                int c = s[i] - '0';
                if (p == '?') {
                    if (pos > -1) {
                        if ((i - pos) % 2 == 0) {
                            if (s[pos] != s[i]) {
                                len = i - pos;
                            } else {
                                len++;
                            }
                        } else {
                            if (s[pos] == s[i]) {
                                len = i - pos;
                            } else {
                                len++;
                            }
                        }
                    } else {
                        len++;
                    }
                } else if (c == p) {
                    len = 1;
                } else {
                    len++;
                }
                pos = i;
                p = c;
            }
            ans += len;
        }
        printf("%lld\n", ans);
    }
}
