#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int temp; scanf("%d", &temp);
            sum += temp;
        }        
        if (sum == m) printf("YES\n"); 
        else printf("NO\n");
    }
}