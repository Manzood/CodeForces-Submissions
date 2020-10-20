#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector <vector <int> a(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
        sort(a[i].begin(), a[i].end());
    }
    for (int i = 0; i < n; i++) {
        // solution incomplete at the moment, will try again later
    }
}