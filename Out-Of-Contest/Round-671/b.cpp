#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        long long pow = 2;
        long long used = 0;
        int ans = 0;
        while (1) {
            long long temp = pow-1;
            used += (temp * (temp + 1)) / 2;
            if (used > x) break;
            ans++;
            pow *= 2;
        }
        printf("%d\n", ans);
    }
}