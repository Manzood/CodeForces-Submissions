#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void not_cycle (int a, int b, int c, int m) {
    vector <int> temp = {a, b, c};
    int dir = 1;
    int ind = 0;
    int cnt = 0;
    while (true) {
        printf("%lld ", temp[ind]);
        cnt++;
        if (cnt == m + 1) break;
        if (ind == 2) dir = -1;
        if (ind == 0) dir = 1;
        ind += dir;
    }
}

void cycle (int a, int b, int c, int m) {
    // is not actually a cycle
    bool flag = true;
    int cnt = 0;
    for (int i = 0; i < m + 1; i++) {
        if (flag) {
            printf("%lld ", a);
        } else {
            if (cnt % 2 == 0) {
                printf("%lld ", b);
            } else {
                printf("%lld ", c);
            }
            cnt++;
        }
        flag ^= 1;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        vector <vector <char>> a(n);
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            for (int j = 0; j < n; j++) {
                a[i].push_back(temp[j]);
            }
        }
        int u = -1, v = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (a[i][j] == a[j][i]) {
                    u = i;
                    v = j;
                }
            }
        }
        if (u == -1 && v == -1 && m % 2 == 0 && n == 2) {
            printf("NO\n");
        } else {
            printf("YES\n");
            if (u == -1 && v == -1) {
                if (m % 2 == 1) {
                    for (int i = 0; i < m + 1; i++) {
                        if (i % 2 == 0) {
                            printf("1 ");
                        } else {
                            printf("2 ");
                        }
                    }
                    printf("\n");
                } else {
                    if (a[0][1] == a[1][2]) {
                        if ((m / 2) % 2 == 1) {
                            not_cycle(1, 2, 3, m);
                        } else {
                            cycle (2, 3, 1, m);
                        }
                    } else if (a[1][2] == a[2][0]) {
                        if ((m / 2) % 2 == 1) {
                            not_cycle (2, 3, 1, m);
                        } else {
                            cycle (3, 1, 2, m);
                        }
                    } else {
                        if ((m / 2) % 2 == 1) {
                            not_cycle (3, 1, 2, m);
                        } else {
                            cycle (1, 2, 3, m);
                        }
                    }
                    printf("\n");
                }
            } else {
                for (int i = 0; i < m + 1; i++) {
                    if (i % 2 == 0) printf("%lld ", u + 1);
                    else printf("%lld ", v + 1);
                }
                printf("\n");
            }
        }
    }
}
