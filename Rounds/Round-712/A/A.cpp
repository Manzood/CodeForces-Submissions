#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

bool is_palindrome (string& s) {
    int n = s.size();
    bool check = true;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) check = false;
    }
    return check;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string s1 = s, s2;
        s2 = "a";
        s2 += s;
        s1 += 'a';
        if (!is_palindrome (s1)) {
            cout << "YES\n";
            cout << s1 << "\n";
        } else if (!is_palindrome(s2)) {
            cout << "YES\n";
            cout << s2 << "\n";
        } else {
            cout << "NO\n";
        }
    }
}
