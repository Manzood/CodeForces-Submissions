#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
// cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector <vector <int>> a(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char x;
                cin >> x;
                cout << x;
                a[i].push_back(x-'0');
            }
            cout << endl;
        }
        if (n > 3 && m > 3) {
            printf("-1\n");
        }
        else if (n > 1 && m > 1) {
            int ans = 0;
            vector <vector <int>> good(n-1);
            vector <vector <int>> dp(n-1);
            for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < m-1; j++) {
                    int sum = a[i][j] + a[i+1][j+1] + a[i][j+1] + a[i+1][j];
                    if (sum % 2 == 0) {
                        good[i].push_back(1);
                    }
                    else {
                        good[i].push_back(0);
                    }
                }
            }
            for (int i = 0; i < sz(good); i++) {
                for (int j = m-2; j >= 0; j--) {
                    if (i == 0 && j == 0) {
                        if (good[i][j] == 1) dp[i][j] = 1;
                        else dp[i][j] = 0;
                    }
                    else if (i == 0) {
                        if (good[i][j] == 1) {
                            if (good[i][j-1] == 1 && (j <= 1 || j ))
                }
            }
            ans += count;
            printf("%d\n", ans);
        }
        else {
            printf("0\n");
        }
    }
}