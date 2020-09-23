#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        long long x, y, k;
        scanf("%lld%lld%lld", &x, &y, &k); 
        x--;
        long long ans = (y * k + k) / x;
        ans += k;
        if ((y * k + k) % x == 0) ans--;
        printf("%lld\n", ans);
    }
}