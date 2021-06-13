#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        // check failure state if WA
        vector <int> a(n);
        int curr = 1;
        int ans = 1;
        int count = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i > 0) {
                if (a[i] > a[i-1]) {
                    curr++;
                    count++;
                    if (curr == k) {
                        ans++;
                        curr = 1;
                    }
                }
            }
        }
        if (curr == 1 && count > 1) {
            ans--;
        }
        if (k == 1 && count > 1) printf("-1\n");
        else printf("%d\n", ans);
    }
}