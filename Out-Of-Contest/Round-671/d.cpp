#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    vector <int> firstbigger(n);
    firstbigger[i-1] = -1;
    int prev = -1;
    for (int i = n-2; i >= 0; i--) {
        if (a[i] < a[i+1]) {
            firstbigger[i] = prev;
            prev = i;
        }
    }
    for (int)
    vector <int> ans(n);
    int startptr = 0, endptr = n-1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans[i] = a[endptr--];
        }
        else {
            ans[i] = a[startptr++];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && i < n-1 && ans[i-1] > ans[i] && ans[i+1] > ans[i]) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}