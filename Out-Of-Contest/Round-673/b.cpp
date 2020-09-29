#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, T;
        scanf("%d%d", &n, &T);
        vector <int> a(n);
        // putting them in a map will be ideal
        map <int, int> mp1;
        map <int, int> mp2;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        vector <int> ans(n);
        for (int i = 0; i < n; i++) {
            int temp = T - a[i];
            if (temp >= 0 && (mp2[temp] > mp1[temp])) {
                ans[i] = 0;
                mp1[a[i]]++;
            }
            else {
                ans[i] = 1;
                mp2[a[i]]++;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
}