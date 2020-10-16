#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        int curr = 0;
        vector <int> a(3, 0);
        int val = 0;
        int first = 0, second = 0, third = 0;
        int found = false;
        while (val <= n && !found) {
            while (val <= n && !found) {
                while (val <= n && !found) {
                    if (val == n) {
                        found = true;
                    }
                    else {
                        val += 3;
                        third++;
                    }
                }
                val -= third * 3;
                if (!found)
                    third = 0;
            }
            if (!found) {
                second = 0;
            }
            else {
                second++;
            }
        }
    }
}