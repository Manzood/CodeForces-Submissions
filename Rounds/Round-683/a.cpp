#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", n);
        for (int i = 0; i < n; i++) {
            printf("%d ", i+1);
        }
        printf("\n");
    }
}