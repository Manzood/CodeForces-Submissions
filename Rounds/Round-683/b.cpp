#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int sum = 0;
        int mi = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num;
                scanf("%d", &num);
                if (num < 0) cnt++;
                if (i == 0 && j == 0) {
                    mi = abs(num);
                } else {
                    mi = min(mi, abs(num));
                }
                sum += abs(num);
            }
        }
        if (cnt % 2 == 0) mi = 0;
        printf("%d\n", sum - 2*mi);
    }
}