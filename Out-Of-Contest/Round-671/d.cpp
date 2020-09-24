#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    // what if I just put the smallest numbers in their potential positions, and then went ahead to
    // fit larger elements that haven't been used yet.
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    vector <int> ans(n);
    vector <bool> used(n, false);
    int usedcnt = 0;
    for (int i = 1; i < n; i += 2) {
        used[usedcnt] = true;
        ans[i] = a[usedcnt++];
    }
    int ansptr = 0;
    for (int i = usedcnt; i < n; i++) {
        if (!used[i]) {
            ans[ansptr] = a[i];
            ansptr += 2;
        }
    }
    int cnt = 0;
    for (int i = 1; i < n-1; i++) {
        if (ans[i] < ans[i-1] && ans[i] < ans[i+1])
            cnt++;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    }