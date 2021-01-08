#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

// remove all even occurances of prime factors, to make things easier?
// everything else is necessary
// reduce everything to the bare essence and then use a set?

map <int, int> mp;
void primeFactors(int n) {
    int val = 1;
    int count = 0;
    // if (n % 2 == 0) val *= 2;
    while (n % 2 == 0) {
        count++;
        if (count % 2 == 0) val /= 2;
        else val *= 2;
        n = n / 2;
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        count = 0;
        // if (n % i == 0) val *= i;
        while (n % i == 0) {
            count++;
            if (count % 2 == 0) val /= i;
            else val *= i;
            n = n / i;
        }
    }
    if (n > 2) {
        val *= n;
    }
    mp[val]++;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        // for (auto &x: mp) {
            // x.second = 0;
        // }
        mp.clear();
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            primeFactors(a[i]);
        }
        int ans = 0;
        int final = 1;
        for (auto x: mp) {
            ans = max(x.second, ans);
            final *= x.second;
        }
        int q; scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            int w; scanf("%d", &w);
            if (w == 0) printf ("%d\n", ans);
            else printf("%d\n", final);
        }
    }
}
