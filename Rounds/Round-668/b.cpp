#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        long long ans = 0; 
        long long pos = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                long long m;
                if (pos < -a[i]) m = pos;
                else m = -a[i];
                a[i] += m; 
                pos -= m;
                ans -= a[i]; 
            }
            else {
                pos += a[i];
            }
        }
        printf("%lld\n", ans);
    }
}