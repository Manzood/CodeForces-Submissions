#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        scanf("%lld%lld%lld", &n, &l, &r);
        map <int, int> left, right;
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%lld", &temp);
            if (i < l) left[temp]++;
            else right[temp]++;
        }
        int ans = 0;
        if (l < r) {
            // move from right to left
            // use priority queue instead, for transfer
            // vector <pair <int, int>> temp;
            priority_queue <pair <int, int>> temp;
            for (auto x: right) {
                // temp.push_back ({x.second, x.first});
                int val = x.second - left[x.first];
                // temp.emplace (x.second, x.first);
                temp.emplace (val, x.first);
            }
            // sort (temp.begin(), temp.end());
            // int ind = temp.size() - 1;
            for (int i = 0; i < (r - l) / 2; i++) {
                pair <int, int> pq_top = temp.top();
                temp.pop();
                // temp.first--;
                pq_top.first-=2;
                left[pq_top.second]++;
                right[pq_top.second]--;
                if (pq_top.first != 0) temp.push (pq_top);
                ans++;
                // if (temp[ind].first == 0) ind--;
            }
        } else {
            // left to right
            // vector <pair <int, int>> temp;
            priority_queue <pair <int, int>> temp;
            for (auto x: left) {
                // temp.push_back ({x.second, x.first});
                int val = x.second - right[x.first];
                // temp.emplace (x.second, x.first);
                temp.emplace (val, x.first);
            }
            // sort (temp.begin(), temp.end());
            // int ind = temp.size() - 1;
            for (int i = 0; i < (l - r) / 2; i++) {
                pair <int, int> pq_top = temp.top();
                temp.pop();
                // temp.first--;
                // printf("currently we have %lld\n", pq_top.second);
                pq_top.first-=2;
                // printf("Moving %lld to right, with score %lld\n", pq_top.second, pq_top.first);
                right[pq_top.second]++;
                left[pq_top.second]--;
                if (pq_top.first != 0) temp.push (pq_top);
                ans++;
            }
        }
        // now the number of left = number of right socks;
        // remove all pairs
        for (auto &x: left) {
            while (x.second > 0) {
                if (right[x.first] > 0) {
                    right[x.first]--;
                    x.second--;
                    // debug(x.first);
                    // debug (x.second);
                    // debug(right[x.first]);
                } else {
                    break;
                }
            }
        }
        for (auto x: left) {
            ans += x.second;
        }
        // for (auto x: right) {
            // ans += x.second;
        // }
        printf("%lld\n", ans);
    }
}
