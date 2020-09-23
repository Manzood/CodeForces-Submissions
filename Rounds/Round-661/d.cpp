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
        cin >> s;
        int curr = 1;
        vector <int> ans(n);
        vector <char> last(n+1);
        char prev;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            char x = s[i];
            if (i == 0) {
                ans[i] = curr;
                last[curr] = x;
            }
            else {
                if (x == prev) {
                    while (curr <= mx && last[curr] == x) {
                        curr++;
                    }
                    ans[i] = curr;
                    last[curr] = x;
                }
                else {
                    curr = 1;
                    ans[i] = curr;
                    last[curr] = x;
                }
            }
            prev = x;
            mx = max (curr, mx);
        }
        printf("%d\n", mx);
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
}