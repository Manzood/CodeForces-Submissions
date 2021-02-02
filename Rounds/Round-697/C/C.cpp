#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int a, b, k;
        scanf("%lld%lld%lld", &a, &b, &k);
        vector <int> adeg(a);
        vector <int> bdeg(b);
        vector <int> A(k);
        vector <int> B(k);
        for (int i = 0; i < k; i++) {
            scanf("%lld", &A[i]); A[i]--;
            adeg[A[i]]++;
        }
        for (int i = 0; i < k; i++) {
            scanf("%lld", &B[i]); B[i]--;
            bdeg[B[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += (k - adeg[A[i]] - bdeg[B[i]] + 1);
        }
        printf("%lld\n", ans / 2);
    }
}
