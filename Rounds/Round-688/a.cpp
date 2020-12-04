#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<< #x << " = " << x << endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        set <int> a;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            a.insert(temp);
        }
        for (int i = 0; i < m; i++) {
            int temp;
            scanf("%d", &temp);
            if (a.count(temp)) ans++;
        }
        printf("%d\n", ans);
    }
}