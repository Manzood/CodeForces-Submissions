#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        bool equal = true;
        for (int i = 0; i < n-1; i++) {
            if (a[i] != a[i+1]) 
                equal = false;
        }
        int ans;
        if (equal == false) 
            ans = 1;
        else 
            ans = n;
        printf("%lld\n", ans);
    }
}