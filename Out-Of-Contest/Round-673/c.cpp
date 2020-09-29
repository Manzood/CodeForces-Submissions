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
        vector <int> prev(n+1, -1);
        vector <int> k(n+1, -1);
        int mi = n+1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            int number = a[i];
            if (prev[number] == -1) {
                k[number] = i+1;
            }
            else {
                k[number] = max(k[number], i - prev[number]);
            }
            prev[number] = i;
            mi = min(a[i], mi);
        }
        for (int i = 1; i <= n; i++) {
            if (prev[i] != -1) {
                k[i] = max(k[i], n - prev[i]);
            }
        }
        vector <int> ans(n, -1);
        for (int i = 1; i <= n; i++) {
            if (k[i] > -1) {
                if (ans[k[i]-1] == -1) {
                    ans[k[i]-1] = i;
                } else {
                    ans[k[i]-1] = min(ans[k[i]-1], i);
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (ans[i-1] > -1) ans[i] = min(ans[i-1], ans[i]); 
            if (ans[i] == -1) ans[i] = max(ans[i], ans[i-1]);
        }
        for (int i = 0; i < n; i++) printf("%d ", ans[i]);
        printf("\n");
    }
}