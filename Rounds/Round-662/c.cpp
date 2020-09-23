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
        vector <int> a(n);
        map <int, int> mp;
        // map <int, int> check;
        int max = 0;
        int maxcount = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            int temp = ++mp[a[i]];
            // ++check[temp];
            if (temp > max) {
                maxcount = 1;
                max = temp;
            }
            else if (temp == max) maxcount++;
        }
        int ans = n - max - (maxcount - 1);
        // debug(ans);
        // debug(max);
        ans /= (max - 1);
        printf("%d\n", ans);
    }
}