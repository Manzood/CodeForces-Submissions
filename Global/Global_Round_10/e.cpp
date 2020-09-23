#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << start << " ";
                start *= 2;
            }
            cout << endl;
        }
        int q;
        cin >> q;
        while (q--) {
            int k;
            cin >> k;
            int start = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // if (i == 0 && j == 0) {
                        // cout << "1 1" << endl;
                    // }
                    // else {
                        if (start & k) {
                            cout << i+1 << " " << j+1 << endl;
                        }
                    // }
                    start *= 2  ;
                }
            }
        }
    }
}