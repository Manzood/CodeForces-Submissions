#include "bits/stdc++.h"
using namespace std;
#define int long long
const int inf = 1e9+7;

// it might be possible that the implementation of the segtree is flawed

vector<string> vec_splitter(string s) {
    s += ','; vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out( vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx, __attribute__ ((unused)) int LINE_NUM) { cerr << endl; } template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef local
    #define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
    #define debug(...) 42
#endif

struct segtree {
    int size;
    vector <long long> sum;
    vector <long long> m;
    vector <long long> mx;
    void init (int n) { // just making our size a power of two
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2*size-1, 0);
        m.assign(2*size-1, inf);
        mx.assign(2*size-1, -inf);
    }
    void build (vector <int>& a) {
        int n = a.size();
        int numzeroes = size-n;
        int counter = 0;
        for (int i = 2*size-2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                sum[i] = 0;
                m[i] = inf;
                mx[i] = -inf;
            }
            else if (n > 0) {
                sum[i] = a[--n];
                m[i] = a[n];
                mx[i] = a[n];
            }
            else {
                sum[i] += sum[2*i+1] + sum[2*i+2];
                m[i] = min(m[2*i+1], m[2*i+2]);
                mx[i] = max(mx[2*i+1], mx[2*i+2]);
            }
        }
    }
    void set (int i, int v) { // setting index i to element v
        set (i, v, 0, 0, size);
    }
    void set (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x] = v;
            m[x] = v;
            mx[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        m[x] = min(m[2 * x + 1], m[2 * x + 2]);
        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
        return;
    }
    long long getsum (int left, int right) { // returns sum between indexes [left, right - 1], inclusive
        return getsum(left, right, 0, 0, size);
    }
    long long getsum (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return 0;
        if (lx >= left && rx <= right) return sum[x];
        int mid = (lx + rx) / 2;
        long long s1 = getsum (left, right, 2 * x + 1, lx, mid);
        long long s2 = getsum (left, right, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
    long long getmin (int left, int right) { // returns min between indexes [left, right - 1], inclusive
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
    long long getmax (int left, int right) { // returns max between indexes [left, right - 1], inclusive
        return getmax (left, right, 0, 0, size);
    }
    long long getmax (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return -inf;
        if (lx >= left && rx <= right) return mx[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmax (left, right, 2 * x + 1, lx, mid);
        long long s2 = getmax (left, right, 2 * x + 2, mid, rx);
        return max(s1, s2);
    }
};

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        vector <int> a(n);
        vector <int> pref(n+1);
        string s; cin >> s;
        pref[0] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '+') a[i] = 1;
            else a[i] = -1;
            pref[i+1] = pref[i] + a[i];
        }
        segtree st;
        st.init(n+1);
        st.build(pref);
        for (int i = 0; i < m; i++) {
            int left, right;
            scanf("%lld%lld", &left, &right);
            left--;
            right--;
            int leftmin = st.getmin (0, left + 1);
            int leftmax = st.getmax (0, left + 1);
            int rightmin = st.getmin (right + 2, n + 1);
            int rightmax = st.getmax (right + 2, n + 1);
            if (rightmin == inf) rightmin = 0;
            if (leftmin == inf) leftmin = 0;
            if (rightmax == -inf) rightmax = 0;
            if (leftmax == -inf) leftmax = 0;
            int val = pref[right + 1];
            int fin = pref[left];
            if (right + 1 == n) val = 0;
            rightmax -= val;
            rightmin -= val;
            rightmax += fin;
            rightmin += fin;
            int mi = min(leftmin, rightmin);
            int mx = max(leftmax, rightmax);
            int ans = mx - mi + 1;
            printf("%lld\n", ans);
        }
    }
}
