#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long

int32_t main() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    if (n == 1) {
        printf("1 1\n0\n1 1\n0\n1 1\n%lld\n", -a[0]);
    }
    else {
        printf("2 %lld\n", n);
        for (int i = 1; i < n; i++) {
            // sketchy part
            // int x = 0;
            // debug(a[i] % n);
            // if (a[i] < 0) {
                // x = (-a[i]) * (n-1);
                // a[i] += x;
            // }
            int rem = a[i] % n;
            int temp = (n-1) * rem;
            printf("%lld ", temp);
            a[i] += temp;
        }
        printf("\n");
        printf("1 1\n");
        printf("%lld\n", -a[0]);
        a[0] = 0;
        printf("1 %lld\n", n);
        for (int i = 0; i < n; i++) {
            printf("%lld ", -a[i]);
        }
        printf("\n");
    }
}