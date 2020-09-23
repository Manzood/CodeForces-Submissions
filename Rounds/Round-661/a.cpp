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
        bool possible = true;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i-1] > 1) 
                possible = false;
        }
        if (possible)
            printf("YES\n");
        else
            printf("NO\n");
    }
}