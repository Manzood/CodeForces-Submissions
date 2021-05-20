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
        string s;
        cin >> s;
        int numzeroes = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') numzeroes++;
        }
        int out = 0;
        for (int i = 0; i < n / 2; i++) {
            if ((s[i] == '0' && s[n - i - 1] != '0') || (s[i] == '1' && s[n - i - 1] != '1')) {
                out++;
            }
        }
        int bob = 0;
        bob += out;
        int cur = numzeroes - out;
        if (numzeroes == 0) {
            printf("DRAW\n");
        } else {
            // if out is zero, old rules apply
            // person who starts even pallindromic state ends up with 2 more
            if (out == 0) {
                if (numzeroes % 2 == 1 && numzeroes > 1) printf("ALICE\n");
                else printf("BOB\n");
            } else {
                if (cur == 1 && out == 1) {
                    printf("DRAW\n");
                } else {
                    printf("ALICE\n");
                }
            }
        }
    }
}
