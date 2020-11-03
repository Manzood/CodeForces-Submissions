#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

struct segtree {
    int size;
    vector <long long> sum;
    void init (int n) { // just making our size a power of two
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2*size-1, 0);
    }
    void build (vector <int>& a) {
        int n = a.size();
        int numzeroes = size-n;
        int counter = 0;
        for (int i = 2*size-2; i >= 0; i--) {
            if (counter++ < numzeroes) sum[i] = 0;
            else if (n > 0) {
                sum[i] = a[--n];
            }
            else {
                sum[i] += sum[2*i+1] + sum[2*i+2];
            }
        }
    }
    void set (int i, int v) {
        set (i, v, 0, 0, size);
    }
    void set (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) { 
            sum[x] = v;
            return;
        }
        int m = (lx + rx) / 2; 
        if (i < m) { 
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2]; 
        return;
    }
    long long getsum (int left, int right) {
        return getsum(left, right, 0, 0, size);
    }
    long long getsum (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return 0;
        if (lx >= left && rx <= right) return sum[x];
        int m = (lx + rx) / 2;
        long long s1 = getsum (left, right, 2 * x + 1, lx, m);
        long long s2 = getsum (left, right, 2 * x + 2, m, rx);
        return s1 + s2;
    }
};

int main() {
    int n, m; scanf("%d%d", &n, &m);
    segtree st;
    st.init(n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    st.build(a);
    for (int i = 0; i < m; i++) {
        int q; scanf("%d", &q);
        if (q == 1) {
            int ind, v;
            scanf("%d%d", &ind, &v);
            st.set(ind, v);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", st.getsum(l, r));
        }
    }
}