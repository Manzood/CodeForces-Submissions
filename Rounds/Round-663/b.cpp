#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char x;
                cin >> x;
                if (i == n-1) {
                    if (x == 'D')
                        ans++;
                }
                if (j == m-1) {
                    if (x == 'R')
                        ans++;
                }
            }
        }               
        printf("%d\n", ans);
    }
}