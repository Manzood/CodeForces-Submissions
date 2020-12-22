#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector <int> a(n); 
        vector <bool> check(n+1, false);
        for (int i = 0; i < n; i++) {
            scanf("%d", a[i]);
            if (a[i] <= i+1 || a[i] >= n-i-1) {
                check[i+1] = true;
            }
        }
        vector <int> ans(n);
        bool stop = false;
        for (int i = 0; i < n; i++) {
            if (check[i] && !stop) ans.push_back(1);
            else ans.push_back(0);
        }
        for (int i = n-1; i >= 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}