#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector <int> a(n);
        set <int> used;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (used.count(a[i])) {
                a[i]++;
                if (!used.count(a[i])) {
                    ans++;
                    used.insert(a[i]);
                }
            }
            else {
                ans++;
                used.insert(a[i]);
            }
        }
        printf("%d\n", ans);
    }
}