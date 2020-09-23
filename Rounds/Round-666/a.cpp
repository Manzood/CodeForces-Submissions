#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        string s;
        map <char, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < sz(s); j++) {
                mp[s[j]]++;
            }
        }
        bool ans = true;
        // stupid silly mistake, didn't change A to B
        for (char i = 'a'; i <= 'z'; i++) {
            if (mp[i] % n != 0) {
                ans = false;
            }
        }
        if (ans) 
            printf("YES\n");
        else 
            printf("NO\n");
    }
}