#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, s, k;
        scanf("%d%d%d", &n, &s, &k);
        vector <int> a(k);
        for (int i=0; i<k; i++) {
            scanf("%d", &a[i]);
        }
        int ans=k+1;
        for (int i=max(1,s-k); i<=min(n,s+k); i++) {
            bool found = false;
            for (int j=0; j<k; j++) {
                if (a[j] == i)
                    found = true;
            }
            if (!found) 
                ans = min (abs(s-i), ans);
        }
        printf("%d\n", ans);
    }
}