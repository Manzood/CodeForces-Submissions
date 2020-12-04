#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector <vector <int>> grid(n);
        for (int i = 0; i < n; i++) {
            grid[i].resize(n);
            for (int j = 0; j < n; j++) {
                char temp;
                cin >> temp;
                grid[i][j] = temp - '0';
            }
        }
        for (int num = 0; num < 10; num++) {
            // find best vertical height
            int cnt = 0;
            int first = -1;
            int second = -1;
            int best = 0;
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == num) {
                        if (cnt == 0) {
                            first = i;
                            best = max (best, max (j, n - j - 1));
                        } else {
                            second = i;
                            best = max (best, max (j, n - j - 1));
                        }
                        cnt++;
                    }
                }
            }
            ans = best * (second - first);
            if (cnt <= 1) {printf("0 "); continue;}
            cnt = 0;
            best = 0;
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    if (grid[i][j] == num) {
                        if (cnt == 0) {
                            first = j;
                            best = max (best, max (i, n - i - 1));
                        } else {
                            second = j;
                            best = max (best, max (i, n - i - 1));
                        }
                        cnt++;
                    }
                }
            }
            ans = max(ans, best * (second - first));
            printf("%d ", ans);
        }
        printf("\n");
    }
}
