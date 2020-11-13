#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector <vector <int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i].resize(m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0 && a[i][j] % 2 == 1) {
                    a[i][j]++;
                }
                if ((i + j) % 2 == 1 && a[i][j] % 2 == 0) {
                    a[i][j]++;
                }
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}