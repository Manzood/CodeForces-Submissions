#include "bits/stdc++.h"
using namespace std;

vector<string> vec_splitter(string s) {
    s += ','; vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}

void debug_out( vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx, __attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>

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


bool check(int val, int i, int j, vector <vector <int>>& a, vector <vector <bool>>& incremented) {
    vector <pair<int, int>> surroundings = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    debug(i, j, val);
    bool possible = true;
    for (auto x: surroundings) {
        if (i + x.first >= 0 && i + x.first < (int)a.size() && j + x.second >= 0 && j + x.second < (int)a[i].size()) {
            if (a[i+x.first][j+x.second] == a[i][j]) {
                possible = false;
            }
        }
    }
    a[i][j]++;
    if (i - 1 >= 0) {
        if (a[i-1][j] == val && !incremented[i-1][j]) {
            possible = check(val+1, i-1, j, a, incremented);
            if (possible) {
                a[i-1][j]++;
                incremented[i-1][j] = true;
            }
        }
    }
    else if (i + 1 < (int)a.size() && !incremented[i+1][j]) {
        if (a[i+1][j] == val) {
            possible = check(val+1, i+1, j, a, incremented);
            if (possible) {
                a[i+1][j]++;
                incremented[i+1][j] = true;
            }
        }
    }
    else if (j - 1 >= 0 && !incremented[i][j-1]) {
        if (a[i][j-1] == val) {
            possible = check(val+1, i, j-1, a, incremented);
            if (possible) {
                a[i][j-1]++;
                incremented[i][j-1] = true;
            }
        }
    }
    else if (j + 1 < (int)a[i].size() && !incremented[i][j+1]) {
        if (a[i][j+1] == val) {
            possible = check(val+1, i, j+1, a, incremented);
            if (possible) {
                a[i][j+1]++;
                incremented[i][j+1] = true;
            }
        }
    }
    if (!possible) a[i][j]--;
    return possible;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector <vector <int>> a(n);
        vector <vector <int>> b(n);
        vector <vector <bool>> incremented(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int temp; scanf("%d", &temp);
                a[i].push_back(temp);
                b[i].push_back(temp);
                incremented[i].push_back(false);
            }
        }
        vector <pair<int, int>> surroundings = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto x: surroundings) {
                    if (i + x.first >= 0 && i + x.first < n && j + x.second >= 0 && j + x.second < m) {
                        if (a[i+x.first][j+x.second] == a[i][j]) {
                            check(a[i][j], i, j, a, incremented);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}