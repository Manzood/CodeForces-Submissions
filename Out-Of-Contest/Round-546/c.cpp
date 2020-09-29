#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            a[i].push_back(temp); 
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int temp;
            scanf("%d", &temp);
            b[i].push_back(temp);
        }
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
        vector <int> t1(0), t2(0);
        int x = i;
        int y = 0;
        while (x >= 0 && y < m) {
            t1.push_back(a[x][y]);
            t2.push_back(b[x][y]);
            x--; y++;
        }
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        for (int j = 0; j < sz(t1); j++) {
            if (t1[j] != t2[j]) ans = false;
        }
        if (ans == false) break;
    }
    for (int i = 0; i < m; i++) {
        vector <int> t1(0), t2(0);
        int x = n-1;
        int y = i;
        while (x >= 0 && y < m) {
            t1.push_back(a[x][y]);
            t2.push_back(b[x][y]);
            x--; y++;
        }
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        for (int j = 0; j < sz(t1); j++) {
            if (t1[j] != t2[j]) ans = false;
        }
        if (ans == false) break;
    }
    ans ? printf("YES\n") : printf("NO\n");
}