#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
// slower, but correct code

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        n *= 2;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a.begin(), a.end());
        vector <int> ans;
        bool possible = false;
        for (int i = 0; i < n - 1; i++) {
            ans.resize(0);
            int x = a[n-1];
            map <int, int> mp;
            set <int> s;
            for (int j = 0; j < n - 1; j++) {
                if (j == i) continue;
                mp[a[j]]++;
                s.insert(a[j]);
            }
            ans.push_back(a[i]);
            ans.push_back(a[n-1]);
            int cnt = n - 2;
            bool found = true;
            while (cnt && found) {
                int mx = *s.rbegin();
                int temp = mp[x - mx];
                if (!mp[x - mx]) {
                    found = false;
                } else {
                    temp--;
                    if (temp == 0) {
                        s.erase(x - mx);
                    }
                    if (mp[mx] == 0) {
                        found = false;
                        break;
                    }
                    if (--mp[mx] == 0) {
                        s.erase(mx);
                    }
                    ans.push_back(x - mx);
                    ans.push_back(mx);
                    x = mx;
                    cnt -= 2;
                }
            }
            if (found) {
                possible = true;
                break;
            }
        }
        if (possible) {
            printf("YES\n");
            printf("%lld\n", ans[0] + ans[1]);
            for (int i = 0; i + 1 < (int)ans.size(); i += 2) {
                printf("%lld %lld\n", ans[i], ans[i+1]);
            }
        } else {
            printf("NO\n");
        }
    }
}
