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
        int n, w;
        scanf("%lld%lld", &n, &w);
        vector <int> a(n);
        vector <int> b(32);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            for (int j = 0; j < 32; j++) {
                if ((1LL << j) & a[i]) {
                    b[j]++;
                    break;
                }
            }
        }
        int ans = 0;
        int last = 0;
        for (int i = 0; i < 32; i++) {
            if (w & (1LL << i)) last = i;
        }
        bool found = false;
        while (!found) {
            int p = last;
            for (int i = last - 1; i >= 0; i--) {
                if (b[i] < b[p]) continue;
                else {
                    int num = b[i];
                    for (int j = i + 1; j <= p; j++) {
                        int c = num % 2;
                        num /= 2;
                        num += c;
                    }
                    b[p] += num;
                    b[i] = b[i] % 2;
                }
            }
            bool check = true;
            for (int i = last - 1; i >= 0; i--) {
                if (b[i] > b[last]) check =false;
            }
            found = check;
        }
        ans = b[last];
        printf("%lld\n", ans);
    }
}
