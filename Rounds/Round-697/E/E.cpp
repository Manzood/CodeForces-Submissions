#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int mod = 1e9+7;

void get_factorial (vector <int>& fact, int n) {
    for (int i = (int) fact.size(); i <= n; i++) {
        if (i > 0) fact.push_back(fact[i - 1] * i);
        else fact.push_back(1);
        fact[i] %= mod;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        vector <int> a(n);
        map <int, int> mp;
        vector <int> factorial;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            mp[a[i]]++;
        }
        sort(a.begin(), a.end());
        int ans = 1;
        int prev = -1;
        int pos = n;
        int smallest = -1;
        for (int i = n - 1; i >= n - k; i--) {
            if (a[i] != prev) {
                smallest = a[i];
                prev = a[i];
                pos = i + 1;
            }
        }
        int cnt = mp[smallest];
        if ((int) factorial.size() <= cnt) {
            get_factorial (factorial, cnt);
        }
        ans *= factorial[cnt];
        int others = n - pos;
        int num = k - others;
        ans /= factorial[num];
        ans /= factorial[cnt - num];
        ans %= mod;
        printf("%lld\n", ans);
    }
}
