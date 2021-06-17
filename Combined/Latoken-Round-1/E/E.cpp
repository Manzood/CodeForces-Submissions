#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    int rem = n % k;
    if (rem % 2 != 0 && ((rem + k) % 2 != 0 || n % 2 == 1)) {
        cout << -1 << endl;
    } else {
        int ans = 0;
        if (rem % 2 == 0) {
            // easy case
            int d = n / k;
            int last = -1;
            for (int i = 0; i < d; i++) {
                cout << "? ";
                for (int j = 0; j < k; j++) {
                    cout << (i * k + j) + 1 << " ";
                    last = i * k + j;
                }
                cout << endl;
                int response;
                cin >> response;
                ans ^= response;
            }
            if (rem) {
                for (int i = 0; i < 2; i++) {
                    int l = rem / 2;
                    cout << "? ";
                    for (int j = 0; j < k - l; j++) {
                        cout << last - j + 1 << " ";
                    }
                    for (int j = 0; j < l; j++) {
                        cout << last + (i * l) + j + 2 << " ";
                    }
                    cout << endl;
                    int response;
                    cin >> response;
                    ans ^= response;
                }
            }
        } else if (n >= 2 * k) {
            // stop when number of remaining numbers <= 2 * k;
            int remaining = n;
            int last = -1;
            while (remaining > 2 * k) {
                cout << "? ";
                for (int i = 0; i < k; i++) {
                    cout << last + 2 << " ";
                    last++;
                }
                cout << endl;
                int response;
                cin >> response;
                ans ^= response;
                remaining -= k;
            }
            for (int i = 0; i < 2; i++) {
                cout << "? ";
                int l = remaining / 2;
                for (int j = 0; j < k - l; j++) {
                    cout << last - j + 1 << " ";
                }
                for (int j = 0; j < l; j++) {
                    cout << last + (i * l) + 2 + j << " ";
                }
                cout << endl;
                int response;
                cin >> response;
                ans ^= response;
            }
        } else {
            // n is even, k is odd
            // discover them 2 * (n - k) at a time
            int cur = 0;
            while (cur < n) {
                int response;
                cout << "? ";
                for (int i = 0; i < n - k; i++) {
                    cout << ((cur + i) % n) + 1 << " ";
                }
                for (int i = 0; i < k - (n - k); i++) {
                    cout << ((cur + 2 * (n - k) + i) % n) + 1 << " ";
                }
                cout << endl;
                cin >> response;
                ans ^= response;
                cout << "? ";
                for (int i = 0; i < n - k; i++) {
                    cout << ((cur + n - k + i) % n) + 1 << " ";
                }
                for (int i = 0; i < k - (n - k); i++) {
                    cout << ((cur + 2 * (n - k) + i) % n) + 1 << " ";
                }
                cout << endl;
                cin >> response;
                ans ^= response;
                cur += 2 * (n - k);
            }
        }
        cout << "! " << ans << endl;
    }
}
