#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int query (int left, int right) {
    int response;
    cout << "? " << left << " " << right << endl;
    cin >> response;
    return response;
}

int32_t main() {
    int n;
    cin >> n;
    int left = 1, right = n;
    int p = query(left, right);
    int mid = (left + right) / 2;
    if (p >= mid) {
        left = mid;
    } else {
        right = mid;
    }
    while (left < right) {
        int cur = query (left, right);
        mid = (left + right) / 2;
        if (cur == p) {
            if (cur >= mid) {
                left = mid;
            } else {
                right = mid;
            }
        } else {
            // go to previous bounds

        }
        p = cur;
    }
    cout << "! " << left << endl;
}
