#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    // make it divisible by k
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    // go from left to right
    string ans;
    while ((int) ans.size() < k) {
        ans += s;
    }
    while ((int) ans.size() > k) ans.pop_back();
    cout << ans << "\n";
}

