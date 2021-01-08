#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        int x = 9;
        for (int i = 0; i < n; i++) {
            if (x == -1) x = 9;
            if (x == 10) x = 0;
            printf("%c", x + '0');
            if (i == 0) x--;
            else x++;
        }
        printf("\n");
    }
}
