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
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        set <int> used;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (used.count(a[i] - a[j]) == 0 && a[i] - a[j] > 0) {
                    used.insert(a[i] - a[j]);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}