#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        int mi = k+1;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (mi > a[i]) {
                mi = a[i];
                ind = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i != ind) {
                ans += (k - a[i]) / mi;
            }
        }
        printf("%d\n", ans);
    }
}