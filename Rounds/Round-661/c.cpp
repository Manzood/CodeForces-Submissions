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
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort (a.begin(), a.end());
        int s[101];
        int mx = 0;
        for (int i = 1; i <= 100; i++) {
            s[i] = 0;
            int j = 0;
            set <int> used;
            while (j < n) {
                while (used.count(j)) {
                    j++;
                }
                for (int x = n-1; x > j; x--) {
                    if (used.count(x)) continue;
                    if (a[j] + a[x] == i) {
                        s[i]++;
                        used.insert(x);
                        used.insert(j);
                        break;
                    }
                    if (a[j] + a[x] < i) 
                        break;
                }
                j++;
            }
            mx = max(s[i], mx);
        }
        printf("%d\n", mx);
    }
}