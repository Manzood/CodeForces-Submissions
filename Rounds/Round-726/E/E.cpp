#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    string ans;
    int ptr = 0;
    int ansptr = n;
    for (int i = 1; i < n; i++) {
        if (s[i] > s[ptr]) {
            ansptr = i;
            break;
        } else if (s[i] == s[ptr]) {
            ptr++;
        } else {
            ptr = 0;
        }
    }
    while ((int) s.size() > ansptr - ptr) s.pop_back();
    while ((int) ans.size () < k) ans += s;
    while ((int) ans.size() > k) ans.pop_back();
    cout << ans << endl;
}

