#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
const int inf = 1e9+7;

struct segtree {
    int size;
    vector <long long> m;
    vector <long long> cnt;
    void init (int n) { // making our size a power of two
        size = 1;
        while (size < n) size *= 2;
        m.assign(2*size-1, inf);
        cnt.assign(2*size-1, 0);
    }
    void build (vector <int>& a) {
        int n = a.size();
        int numzeroes = size-n;
        int counter = 0;
        for (int i = 2*size-2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                m[i] = inf;
                cnt[i] = 0;
            }
            else if (n > 0) {
                m[i] = a[--n];
                cnt[i] = 1;
            }
            else {
                m[i] = min(m[2 * i + 1], m[2 * i + 2]);
                if (m[2 * i + 1] == m[i]) cnt[i] += cnt[2 * i + 1];
                if (m[2 * i + 2] == m[i]) cnt[i] += cnt[2 * i + 2];
            }
        }
        for (auto x: cnt) {
            printf("%lld ", x);
        }
        printf("\n");
        for (auto x: m) {
            printf("%lld ", x);
        }
        printf("\n");
    }
    void set (int i, int v) {
        set (i, v, 0, 0, size);
    }
    void set (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) { 
            m[x] = v;
            return;
        }
        int mid = (lx + rx) / 2; 
        if (i < mid) { 
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        m[x] = min(m[2 * x + 1], m[2 * x + 2]); 
        if (m[2 * x + 1] == m[x]) cnt[x] += cnt[2 * x + 1];
        if (m[2 * x + 2] == m[x]) cnt[x] += cnt[2 * x + 2];
        return;
    }
    long long getmin (int left, int right) {
        return getmin(left, right, 0, 0, size);
    }
    long long getmin (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return inf;
        if (lx >= left && rx <= right) return m[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmin (left, right, 2 * x + 1, lx, mid);
        long long s2 = getmin (left, right, 2 * x + 2, mid, rx);
        return min(s1, s2);
    }
    long long getcnt (int left, int right) {
        return getcnt (left, right, 0, 0, size);
    }
    long long getcnt (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return 0;
        if (lx >= left && rx <= right) return cnt[x];
        int mid = (lx + rx) / 2;
        long long retval = 0;
        retval += getcnt (left, right, 2 * x + 1, lx, mid);
        retval += getcnt (left, right, 2 * x + 2, mid, rx);
        return retval;
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
            printf("%lld ", st.getmin(l, r));
            printf("%lld\n", st.getcnt(l, r));
        }
    }
}