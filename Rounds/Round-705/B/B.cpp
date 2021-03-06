#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int h, m;
        scanf("%lld%lld", &h, &m);
        string s;
        cin >> s;
        int curhours = 0;
        int curmins = 0;
        int mult = 10;
        bool two = false;
        vector <int> check = {0, 1, 2, 5, 8};
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == ':') {
                mult = 10;
                two = true;
                continue;
            }
            if (!two)
                curhours += (s[i] - '0') * mult;
            else
                curmins += (s[i] - '0') * mult;
            mult /= 10;
        }
        int anshours = 0;
        int ansmins = 0;
        for (int i = 0; i < 100000; i++) {
            if (curmins == m) {
                curmins = 0;
                curhours++;
                if (curhours == h) {
                    curhours = 0;
                }
            }
            // check validity
            int temp = curhours;
            bool valid = true;
            int newh = 0;
            while (temp) {
                bool found = false;
                if (temp % 10 == 5) {
                    temp -= 3;
                } else if (temp % 10 == 2) {
                    temp += 3;
                }
                for (auto x: check) {
                    if (temp % 10 == x) {
                        found = true;
                    }
                }
                newh += temp % 10;
                newh *= 10;
                if (!found) {
                    valid = false;
                }
                temp /= 10;
            }
            newh /= 10;
            if (curhours < 10) newh *= 10;
            int newm = 0;
            if (newh >= m) valid = false;
            temp = curmins;
            while (temp) {
                bool found = false;
                if (temp % 10 == 5) {
                    temp -= 3;
                } else if (temp % 10 == 2) {
                    temp += 3;
                }
                for (auto x: check) {
                    if (temp % 10 == x) {
                        found = true;
                    }
                }
                newm += temp % 10;
                newm *= 10;
                    temp /= 10;
                if (!found) {
                    valid = false;
                }
            }
            newm /= 10;
            if (curmins < 10) newm *= 10;
            if (newm >= h) valid = false;
            // if (curmins == 28) {
                // debug(newm);
                // debug(valid);
            // }
            // if (m == 100) {
                // debug(newm);
            // }
            if (valid) {
                anshours = curhours;
                ansmins = curmins;
                break;
            }
            curmins++;
        }
        if (anshours < 10) printf("0");
        printf("%lld:", anshours);
        if (ansmins < 10) printf("0");
        printf("%lld\n", ansmins);
    }
}
