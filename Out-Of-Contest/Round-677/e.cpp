#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int n;
    scanf("%d", &n);
    long long ans = 1;
    int first = n-1;
    for (int i = 0; i < n/2 -1 ; i++) {
        ans *= first;
        first--;
    }
    for (int i = n/2 - 1; i > 1; i--) {
        ans *= i;
    }
    printf("%lld\n", ans);
}