#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        long long sum = 0;
        int high = 0;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] % x) high++;
            high += a[i] / x;
            sum += a[i];
        }
        int low = sum / x;
        if (sum % x) low++;
        printf("%d %d\n", low, high);
    }
}