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
        vector <vector <char>> a(n);
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            for (int j = 0; j < m; j++) {
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
                    vector <int> temp = {1, 2, 3};
                    int ind = 0;
                    int dir = 1;
                    if (a[0][1] == a[1][2]) {
                        ind = 0;
                    } else if (a[1][2] == a[2][0]) {
                        temp = {2, 3, 1};
                    } else {
                        temp = {3, 1, 2};
                    }
                    for (int i = 0; i < m + 1; i++) {
                        printf("%lld ", temp[ind]);
                        if (ind == 2) dir = -1;
                        if (ind == 0) dir = 1;
                        ind += dir;
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
