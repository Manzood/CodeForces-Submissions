#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector <int> a(n);
        int diff = 0;
        bool one = false;
        bool all = true;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            diff += (x - a[i]);
            if (a[i] == x) one = true;
            else all = false;
        }
        if (diff == 0) one = true;
        if (all) {
            printf("0\n");
        }
        else if (one) {
            printf("1\n");
        }
        else {
            printf("2\n");
        }
    }
}