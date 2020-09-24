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
        bool possible = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i > 0) {
                if (a[i] >= a[i-1]) possible = true;
            }
        }
        if (possible) printf("YES\n");
        else printf("NO\n");
    }
}