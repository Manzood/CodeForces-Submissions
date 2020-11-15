#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    string a, b;
    cin >> a >> b;
    vector <vector <int>> c(n+1);
    vector <vector <int>> repeats(n+1);
    for (int i = 0; i <= n; i++) {
        c[i].resize(m+1);
        repeats[i].resize(m+1);
        c[i][0] = 0;
        repeats[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        c[0][i] = 0;
        repeats[0][i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                repeats[i][j] = repeats[i-1][j-1] + 1;
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                c[i][j] = max(c[i][j-1], c[i-1][j]);
                if (c[i][j] != 0) {
                    if (c[i-1][j] == c[i][j-1]) repeats[i][j] = min(repeats[i-1][j], repeats[i][j-1]) + 1;
                    else {
                        if (c[i-1][j] > c[i][j-1]) {
                            repeats[i][j] = repeats[i-1][j] + 1;
                        } else {
                            repeats[i][j] = repeats[i][j-1] + 1;
                        }
                    }
                }
            }
            ans = max(ans, 4*c[i][j] - c[i][j] - repeats[i][j]);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%lld ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%lld ", repeats[i][j]);
        }
        printf("\n");
    }
    printf("%lld\n", ans);
}