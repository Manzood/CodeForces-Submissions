#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        scanf("%d%d%d%d", &n, &m, &a, &b);
        if (n * a != m * b) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
            int start = 0;
            int end = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((j < start || j >= start + a) && j > end) {
                        printf("0");
                    }
                    else {
                        printf("1");
                    }
                }
                start++;
                if (start + a >= m) {
                    end = start + a - m;
                }
                printf("\n");
            }
        }
    }
}