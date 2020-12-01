#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int cur = 0;
        int ans = 0;
        for (int i = 1; cur < n; i++) {
            cur += i;
            ans++;
        }
        if (cur - n == 1) ans++;
        printf("%d\n", ans);
    }
}