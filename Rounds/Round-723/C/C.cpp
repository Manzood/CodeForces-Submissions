#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    priority_queue <int, vector<int>, greater<int> > pq;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        pq.push (a[i]);
        cnt++;
        if (sum < 0) {
            cnt--;
            int t = pq.top();
            pq.pop();
            sum -= t;
        }
    }
    printf("%lld\n", cnt);
}
