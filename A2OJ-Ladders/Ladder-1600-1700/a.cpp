#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    string s;
    cin >> s;
    set <char> letters;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (letters.count(s[i]) == 0) {
            ans++;
            letters.insert(s[i]);
        }
    }
    ans & 1 ? printf("IGNORE HIM!\n") : printf("CHAT WITH HER!\n");
}