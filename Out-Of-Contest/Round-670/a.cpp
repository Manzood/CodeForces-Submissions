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
        sort(a.begin(), a.end());
        vector <int> ansA, ansB;
        int bprev = -1;
        int aprev = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ansA.push_back(a[i]);
                if (a[i] == 0) aprev = 0;
            }
            else {
                if (a[i] == a[i-1] && a[i] == bprev+1) {
                    ansB.push_back(a[i]);
                    bprev = a[i];
                }
                else if (a[i] == aprev+1) {
                    ansA.push_back(a[i]);
                    aprev = a[i];
                }
            }
        }
        int ans = 0;
        ans = aprev + bprev + 2;
        printf("%d\n", ans);
    }
}