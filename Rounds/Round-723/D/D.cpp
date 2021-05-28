#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector <int> A;
        vector <int> N;
        vector <int> T;
        vector <int> O;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') A.push_back (i);
            if (s[i] == 'N') N.push_back (i);
            if (s[i] == 'T') T.push_back (i);
            if (s[i] == 'O') O.push_back (i);
        }
        // generate all permutations
        vector <int> place = {1, 2, 3, 4};
        vector <int> temp = {'A', 'N', 'T', 'O'};
        vector <string> ans;
        int ansind = 0;
        int mx = 0;
        do {
            string te;
            int val = 0;
            for (auto x: place) {
                if (x == 1) {
                    for (int i = 0; i < (int) A.size(); i++) {
                        te += 'A';
                        val += abs (A[i] - (int) te.size());
                    }
                }
                if (x == 2) {
                    for (int i = 0; i < (int) N.size(); i++) {
                        te += 'N';
                        val += abs (N[i] - (int) te.size());
                    }
                }
                if (x == 3) {
                    for (int i = 0; i < (int) T.size(); i++) {
                        te += 'T';
                        val += abs (T[i] - (int) te.size());
                    }
                }
                if (x == 1) {
                    for (int i = 0; i < (int) O.size(); i++) {
                        te += 'O';
                        val += abs (O[i] - (int) te.size());
                    }
                }
                if (val > mx) {
                    ansind = ans.size();
                    mx = val;
                }
            }
            debug (te);
            debug (val);
            ans.push_back (te);
        } while (next_permutation (place.begin(), place.end()));
        for (int i = 0; i < n; i++) {
            printf("%c", ans[ansind][i]);
        }
        printf("\n");
    }
}
