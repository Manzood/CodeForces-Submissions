#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector <int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        long long cost = 0;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            if (ind < m && a[i] - 1 >= ind) cost += b[ind++];
            else cost += b[a[i]-1];
        }
        printf("%lld\n", cost);
    }
}