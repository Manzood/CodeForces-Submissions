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
        int sum = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            mx = max(a[i], mx);
        }
        int ans = 0;
        if (n < 3) {
            if (n == 2) {
                if (a[0] == a[1]) 
                    ans = 1;
            }
        }
        else {
            if (sum % 2 == 0) ans = 1;
            if (mx > sum - mx) ans = 0;
        }
        if (ans == 0) {
            printf("T\n");
        }
        else {
            printf("HL\n");
        }
    }
}