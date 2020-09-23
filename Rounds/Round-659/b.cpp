#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
    cin >> t;
    while (t--) {
        int n, k, l;
        scanf("%d%d%d", &n, &k, &l);
        vector <int> a(n);
        int curr = k;
        int dir = -1;
        bool possible = true;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int pos = -1;
        while (pos < n - 1 && possible == true) {
            if (pos > 0 && a[pos] + k <= l) {
                curr = k;
                dir = -1;
            }
            if (a[pos+1] + curr > l) {
                if (dir == -1) {
                    curr = l - a[pos+1];
                    if (pos > 0 && a[pos] + curr + 1 > l) possible = false;
                    if (curr < 0) possible = false;
                }
                else 
                    possible = false;
            }
            if (curr == 0) 
                dir = 1;
            if (curr == k) 
                dir = -1;
            curr += dir;
            pos++;
        }
        // debug (possible);
        if (possible) printf("Yes\n");
        else printf("No\n");
    }
}