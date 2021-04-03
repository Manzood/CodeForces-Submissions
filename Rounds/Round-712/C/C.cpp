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
        bool possible = true;
        int asum = 0, bsum = 0;
        string a, b;
        int onecnt = 0;
        int zerocnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                onecnt++;
            } else {
                zerocnt++;
            }
        }
        int onesfound = 0;
        int zero = 0;
        if (onecnt % 2 != 0 || zerocnt % 2 != 0) {
            possible = false;
        } else {
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    if (onesfound < onecnt / 2) {
                        a += '(';
                        b += '(';
                        asum++; bsum++;
                    } else {
                        a += ')';
                        b += ')';
                        asum--; bsum--;
                    }
                    onesfound++;
                } else {
                    if (zero) {
                        a += ')';
                        b += '(';
                        asum--; bsum++;
                    } else {
                        a += '(';
                        b += ')';
                        asum++; bsum--;
                    }
                    zero ^= 1;
                }
                if (asum < 0 || bsum < 0) possible = false;
            }
        }
        if (asum != 0 || bsum != 0) possible = false;
        if (possible) {
            printf("YES\n");
            cout << a << "\n";
            cout << b << "\n";
        } else {
            printf("NO\n");
        }
    }
}
