#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        bool first = false;
        if (!(n & 1)) {
            first = true;
        }
        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i % 2 == 0) {
                if ((s[i]-'0') % 2 == 1) {
                    first = true;
                }
            }
            else if (n % 2 == 0 && i & 1) {
                if ((s[i]-'0') % 2 == 0) {
                    first = false;
                }
            }
        }
        if (first) 
            printf("1\n");
        else 
            printf("2\n");
    }
}