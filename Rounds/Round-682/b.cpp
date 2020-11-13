#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        set <int> a;
        bool ans = false;
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            if (a.count(temp)) ans = true;
            a.insert(temp);
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
}