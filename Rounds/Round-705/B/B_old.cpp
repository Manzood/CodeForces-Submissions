#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int h, m;
        scanf("%lld%lld", &h, &m);
        vector <int> storage;
        storage.push_back(h / 10);
        storage.push_back(h % 10);
        storage.push_back(3824);
        storage.push_back(m / 10);
        storage.push_back(m % 10);
        // int upwardchange = 0;
        int hours = 0, mins = 0;
        string s;
        cin >> s;
        hours += s[0] - '0';
        hours *= 10;
        hours += s[1] - '0';
        mins += s[3] - '0';
        mins *= 10;
        mins += s[4] - '0';
        // upwardchange = m - mins + (h - hours) * 100;
        vector <int> valid = {0, 1, 2, 5, 8};
        vector <int> ans;
        for (int i = 4; i >= 0; i--) {
            int change = 1000;
            int cur = 0;
            if (s[i] == ':') {
                ans.push_back(1324);
                continue;
            }
            bool okay = false;
            for (auto k: valid) {
                if (s[i] - '0' == k) {
                    okay = true;
                }
            }
            if (!okay) {
                for (auto k: valid) {
                    // change = min(abs(k - (s[i] - '0')), change);
                    if (k > storage[i]) continue;
                    if (abs(k - (s[i] - '0')) < change) {
                        cur = k;
                    }
                }
                change = min(storage[i] - (s[i] - '0'), change);
                if (abs(storage[i] - (s[i] - '0')) < change) {
                    cur = 0;
                }
                ans.push_back(cur);
            } else {
                ans.push_back(s[i] - '0');
            }
        }
        for (int i = 4; i >= 0; i--) {
            if (i == 2) {
                printf(":");
            } else {
                printf("%lld", ans[i]);
            }
        }
        printf("\n");
    }
}
