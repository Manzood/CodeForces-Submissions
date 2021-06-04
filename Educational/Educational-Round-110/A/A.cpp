#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        vector <pair <int, int>> s(4);
        for (int i = 0; i < 4; i++) {
            scanf("%lld", &s[i].first);
            s[i].second = i;
        }
        sort (s.begin(), s.end());
        int low = s[3].second;
        int high = s[2].second;
        if (low > high) {
            swap (low, high);
        }
        if (low < 2 && high > 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
