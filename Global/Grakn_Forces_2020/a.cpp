#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        vector <int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                if (i < n-1) {
                    if (a[i] == ans[i-1]) {
                        ans[i] = b[i];
                    }
                    else {
                        ans[i] = a[i];
                    }
                }
                else {
                    if (a[i] == ans[i-1]) {
                        if (b[i] == a[0]) {
                            ans[i] = c[i];
                        }
                        else {
                            ans[i] = b[i];
                        }
                    }
                    else {
                        if (a[i] == ans[0]) {
                            if (b[i] == ans[i-1]) {
                                ans[i] = c[i];
                            }
                            else {
                                ans[i] = b[i];
                            }
                        }
                        else {
                            ans[i] = a[i];
                        }
                    }
                }
            }
            else {
                ans[i] = a[i];
            }
            printf("%d ", ans[i]);
        } 
        printf("\n");
    }
}