#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        string s;
        cin >> s;
        bool possible = true;
        if (n % k != 0) {
            possible = false;
        }
        int p = -1;
        map <char, int> mp;
        vector <pair<int, char>> occurances;
        char te = '@';
        int tot = 0;
        vector <char> ans;
        // finding index
        bool needed = false;
        for (int i = 0; i < n; i++) {
            if (mp[s[i]] == 0) {
                if (tot == n / k) {
                    needed = true;
                    if (s[i] < 'z') {
                        p = i - 1;
                        mp[s[i-1]] = 0;
                        te = s[i - 1];
                        // mp[s[]] // continue coding here
                        break;
                    }
                } else {
                    tot++;
                }
            }
            mp[s[i]]++;
        }

        for (auto x: mp) {
            occurances.push_back({x.second, x.first});
        }
        sort(occurances.begin(), occurances.end());
        if (needed && p == -1) possible = false;
        if (needed && p != -1) {
            for (int i = 0; i < p; i++) {
                ans.push_back(s[i]);
            }
            ans.push_back(s[p] + 1);
        }
        vector <int> temp;
        int ind = (int) occurances.size() - 1;
        for (int i = n - 1; i >= 0 && i > p; i--) {
            while (occurances[ind].first % k == 0 && ind > 0) {
                ind--;
            }
            occurances[ind].first++;
            temp.push_back(occurances[ind].second);
        }
        for (int i = (int) temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
        if (possible) {
            for (int i = 0; i < n; i++) {
                printf("%c", ans[i]);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
}
