#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        int count = 0;
        int zerocount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i < n-1 && s[i+1] == '1') {
                    count++;
                }
            } else {
                if (i < n-1 && s[i+1] == '0') {
                    zerocount++;
                }
            }
        }
        printf("%d\n", max(count, zerocount));
    }
}