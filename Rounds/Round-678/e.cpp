#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

// putting the current solution on hold as I currently lack any knowledge of segment trees whatsoever, but I will (hopefully) be back in a couple of weeks.

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    vector <int> count(n+1);
    vector <int> mex;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int current = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) mex.push_back(2);
        count[a[i]]++;
        if (a[i] == current) {
            while (count[++current]);
        }
        mex.push_back(current);
    }
    for (int i = 0; i < n-1; i++) {
        count[a[i]]--;
        if (count[a[i]] == 0) {
            current = min(a[i], current);
        }
        mex.push_back(current);
    }
    // for (auto x: mex) debug(x);
    sort(mex.begin(), mex.end());
    current = 1;
    for (int i = 0; i < (int)mex.size(); i++) {
        if (mex[i] == current) {
            current++;
        } else if (mex[i] > current) {
            break;
        }
    }
    printf("%d\n", current);
}