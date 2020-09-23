#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int MX = (int)1e5+1;

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    map <int, int> mp;
    int sqcount = 0;
    int twocount = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]]++;
        if (mp[a[i]] % 4 == 0) {
            sqcount++;
            twocount--;
        }
        else if (mp[a[i]] % 2 == 0) {
            twocount++;
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        char x; cin >> x;
        int curr;
        scanf("%d", &curr);
        // debug(curr);
        // debug(x);
        if (x == '+') {
            int temp = ++mp[curr];
            if (temp % 4 == 0) {
                sqcount++;
                twocount--;
            }
            else if (temp % 2 == 0) twocount++;
        }
        if (x == '-') {
            int temp = --mp[curr];
            if ((temp + 1) % 4 == 0) {
                sqcount--;
                twocount++;
        }
            else if ((temp + 1) % 2 == 0) twocount--;
        }
        bool ans = false;
        if (sqcount > 1) ans = true;
        if (sqcount > 0 && twocount > 1) ans = true;
        if (ans) printf("YES\n");
        else printf("NO\n");
        // debug(sqcount);
        // debug(twocount);
    }
}