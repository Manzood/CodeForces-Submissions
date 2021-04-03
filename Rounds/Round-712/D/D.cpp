#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    cin >> n;
    bool onefinished = false;
    bool twofinished = false;
    int twoi = 0, twoj = 1;
    int onei = 0, onej = 0;
    for (int i = 0; i < n * n; i++) {
        int block;
        cin >> block;
        if (!twofinished && block == 1) {
            cout << "2 " << twoi + 1 << " " << twoj + 1 << endl;
            twoj += 2;
            if (twoj >= n) {
                twoi++;
                if (twoi % 2 == 0) {
                    twoj = 1;
                } else {
                    twoj = 0;
                }
            }
            if (twoi >= n) twofinished = true;
        } else if (!onefinished && block == 2) {
            cout << "1 " << onei + 1 << " " << onej + 1 << endl;
            onej += 2;
            if (onej >= n) {
                onei++;
                if (onei % 2 == 1) {
                    onej = 1;
                } else {
                    onej = 0;
                }
            }
            if (onei >= n) onefinished = true;
        } else {
            if (onefinished) {
                if (block != 3) cout << "3 ";
                else cout << "2 ";
                cout << twoi + 1 << " " << twoj + 1 << endl;
                twoj += 2;
                if (twoj >= n) {
                    twoi++;
                    if (twoi % 2 == 0) {
                        twoj = 1;
                    } else {
                        twoj = 0;
                    }
                }
                if (twoi >= n) twofinished = true;
            } else {
                if (block != 3) cout << "3 ";
                else cout << "1 ";
                cout << onei + 1 << " " << onej + 1 << endl;
                onej += 2;
                if (onej >= n) {
                    onei++;
                    if (onei % 2 == 1) {
                        onej = 1;
                    } else {
                        onej = 0;
                    }
                }
                if (onei >= n) onefinished = true;
            }
        }
    }
}
