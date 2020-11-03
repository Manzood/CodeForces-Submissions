#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        // n^2 soln
        int n;
        scanf("%d", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }        
        sort(a.begin(), a.end());
        int free = 0;
        int penalty = 0;
        int prev = 0;
        int prevfree = 0;
        int remaining = n; 
        int current = 1;
        int ind = 0;
        while (remaining) {
            if (current = a[ind])
            current++;
        }
        printf("%d\n", penalty);
    }
}