#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'A') continue;
            if (i + 2 < (int)s.size() && s[i+2] == s[i]) {
                ans++;
                s[i+2] = 'A';
            }
            if (i + 1 < (int)s.size() && s[i+1] == s[i]) {
                ans++;
                s[i+1] = 'A';
            }
        }
        printf("%d\n", ans);
    }
}