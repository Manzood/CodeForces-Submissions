#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        scanf("%d%lld", &n, &k);
        int m0 = 0;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i == 0) m0 = a[i];
            else m0 = max(a[i], m0);
        }
        vector <int> odd(n);
        vector <int> even(n);
        int m1 = 0;
        for (int i = 0; i < n; i++) {
            odd[i] = m0 - a[i];
            if (i == 0) m1 = odd[i];
            else m1 = max(odd[i], m1);
        }
        for (int i = 0; i < n; i++) {
            even[i] = m1 - odd[i];
        }
        if (k % 2 == 0) {
            for (int i = 0; i < n; i++) {
                printf("%d ", even[i]);
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                printf("%d ", odd[i]);
            }
        }
        printf("\n");
    }
}