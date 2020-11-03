#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int x = r + 1;
        int check = x / 2;
        if (x % 2) check++;
        if (l % x >= check) printf("YES\n");
        else printf("NO\n");
    }
}