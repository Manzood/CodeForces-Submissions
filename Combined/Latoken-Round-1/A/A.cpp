#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        vector <vector <char>> a(n, vector <char> (m));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                a[i][j] = s[j];
            }
        }
        bool ans = true;
        char p1 = '.';
        char p2 = '.';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0) {
                    if (p2 == '.') {
                        p2 = a[i][j];
                    } else {
                        if (a[i][j] != '.' && p2 != a[i][j]) {
                            ans = false;
                        }
                    }
                } else {
                    if (p1 == '.') {
                        p1 = a[i][j];
                    } else {
                        if (a[i][j] != '.' && p1 != a[i][j]) {
                            ans = false;
                        }
                    }
                }
            }
        }
        if (p1 != '.' && p2 != '.' && p1 == p2) ans = false;
        if (p1 == 'R') p2 = 'W';
        if (p1 == 'W') p2 = 'R';
        if (p2 == 'W') p1 = 'R';
        if (p2 == 'R') p1 = 'W';
        if (p1 == '.' && p2 == '.') {
            p1 = 'R';
            p2 = 'W';
        }
        if (ans) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((i + j) % 2 == 0) {
                        a[i][j] = p2;
                    } else {
                        a[i][j] = p1;
                    }
                }
            }
            printf("YES\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%c", a[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("NO\n");
        }
    }
}

