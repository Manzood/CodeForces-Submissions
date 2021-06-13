#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <pair <int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok (int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs (int i, int j, int n, int m, vector <vector <char>>& a) {
    for (auto p: dirs) {
        int x = p.first;
        int y = p.second;
        char ch = a[i][j];
        if (ok (i + x, j + y, n, m)) {
        }
    }
}

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
        for (int k = 0; k < (n * m) / 2; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 'R') {
                        for (auto x: dirs) {
                            if (ok(i + x.first, j + x.second, n, m)) {
                                if (a[i + x.first][j + x.second] == 'R') ans = false;
                                else a[i + x.first][j + x.second] = 'W';
                            }
                        }
                    }
                    if (a[i][j] == 'W') {
                        for (auto x: dirs) {
                            if (ok(i + x.first, j + x.second, n, m)) {
                                if (a[i + x.first][j + x.second] == 'W') ans = false;
                                else a[i + x.first][j + x.second] = 'R';
                            }
                        }
                    }
                }
            }
        }
        if (ans) {
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

