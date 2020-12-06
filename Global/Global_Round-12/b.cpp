#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector <pair <int, int>> x;
        for (int i = 0; i < n; i++) {
            int x1, y1; 
            scanf("%d%d", &x1, &y1);
            x.emplace_back(x1, y1);
        }
        bool ans = false;
        for (int i = 0; i < n; i++) {
            bool current = true;
            for (int j = 0; j < n; j++) {
                if (abs(x[i].first - x[j].first) + abs(x[i].second - x[j].second) > k)  {
                    current = false;
                    break;
                } 
            }
            if (current) {
                ans = true;
                break;
            }
        }
        ans ? printf("1\n") : printf("-1\n");
    }
}