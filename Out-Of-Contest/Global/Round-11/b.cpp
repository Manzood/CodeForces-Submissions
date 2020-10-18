#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        string s; cin >> s;
        for (int i = 1; i < n-1; i++) {
            if (k > 0 && s[i] == 'L') {
                if (s[i-1] == 'W' && s[i+1] == 'W') {
                    s[i] = 'W';
                    k--;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (k > 0 && s[i] == 'L') {
                if ((i > 0 && s[i-1] == 'L') || (i < n-1 && s[i+1] == 'L')) {
                    s[i] = 'W';
                    k--;
                }
            }
        }
        int score = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                if (i > 0 && s[i-1] == 'W') score++;
                score++;
            }
            else {
                if (k) {
                    score++;
                    s[i] = 'W';
                    if (s[i-1] == 'W') score++;
                    k--;
                }
            }
        }
        printf("%d\n", score);
    }
}