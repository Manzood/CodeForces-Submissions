#include "bits/stdc++.h"
using namespace std;
#define int long long

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

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, W;
        scanf("%lld%lld", &n, &W);
        vector <int> a(n), w(25, 0);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            for (int j = 0; (1LL << j) <= a[i]; j++) {
                if ((1LL << j) == a[i]) {
                    w[j]++;
                }
            }
        }
        int cnt = n;
        int cur = W;
        int ans = 1;
        while (cnt) {
            // debug(cur);
            // debug(ans);
            int ind = -1;
            for (int i = 0; i < 25; i++) {
                if (w[i] && (1 << i) <= cur) {
                    ind = i;
                }
            }
            if (ind == -1) {
                ans++;
                cur = W;
            } else {
                cur -= (1LL << ind);
                cnt--;
                w[ind]--;
            }
        }
        printf("%lld\n", ans);
    }
}
