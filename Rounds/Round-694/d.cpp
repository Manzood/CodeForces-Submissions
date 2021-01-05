#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

// remove all even occurances of prime factors, to make things easier?
// everything else is necessary
// it shouldn't be a herculean task
map <int, int> mp;
void primeFactors(int n) {
    int val = 1;
    if (n % 2 == 0) val *= 2;
    while (n % 2 == 0) {
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        if (n % i == 0) val *= i;
        while (n % i == 0) {
            n = n/i;  
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
        for (auto &x: mp) {
            x.second = 0;
        }
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            primeFactors(a[i]);
        }
        int ans = 0;
        for (auto x: mp) {
            debug(x.second);
            ans = max(x.second, ans);
        }
        int q; scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            int w; scanf("%d", &w);
            printf ("%d\n", ans);
        }
    }
}