#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long k;
        scanf("%lld", &k);
        if (k < 2) {
            printf("-1\n");
            continue;
        }
        k -= 2;
        vector <int> b;
        long long cur = 1;
        for (int i = 0; i < 63 && cur <= k; i++) {
            if (k & cur) b.push_back(1);
            else b.push_back(0);
            cur = cur << 1;
        }
        vector <int> ans;
        ans.push_back(1);
        // printf("Printing binary\n");
        // for (auto x: b) {
        //     printf("%d ", x);
        // }
        // printf("\nDone\n");
        for (int i = 1; i < (int)b.size(); i++) {
            if (b[i] == 1) {
                for (int j = 0; j < i-1; j++) {
                    ans.push_back(0);
                }
                ans.push_back(1);
            }
        }
        if ((int)ans.size() > 2000) printf("-1\n");
        else {
            printf("%d\n", (int)ans.size());
            for (auto x: ans) {
                printf("%d ", x);
            }
            printf("\n");
        }
    }
}
