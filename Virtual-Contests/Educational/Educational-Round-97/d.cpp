#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        int height = 1;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        vector <int> remaining(1, 1);
        remaining.push_back(1);
        int ind = 1;
        int current = 0;
        for (int i = 2; i < n; i++) {
            if (a[i] < a[i-1]) {
                --remaining[current];
                if (remaining[current] == 0) {
                    ++current;
                    height++;
                    ++ind;
                    if (ind == (int)remaining.size()) remaining.push_back(1); 
                }
            } else {
                remaining[ind]++;
            }
        }
        printf("%d\n", height);
    }
}