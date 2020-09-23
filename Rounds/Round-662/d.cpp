#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector <vector <char> > grid(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char temp;
                cin >> temp;
                grid[i].push_back(temp);
            }
            // scanf("\n");
        }
        int ans = n*m;
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                char x = grid[i][j];
                int start = 3;
                int curr = start;
                bool looking = true;
                while (looking) {
                    bool check = true;
                    int temp = i;
                    while (curr > 0) {
                        if (j + curr/2 >= m || j - curr/2 < 0 || i - curr/2 < 0 || i + curr/2 >= n) {
                            check = false;
                            break;
                        }
                        else if (temp == i) {
                            if (grid[temp][j+curr/2] != x || grid[temp][j-curr/2] !=x) {
                                check = false;
                            }
                        }
                        else {
                            if (grid[temp][j+curr/2] != x || grid[i+(i-temp)][j+curr/2] != x || grid[temp][j-curr/2] != x || grid[i+i-temp][j-curr/2] != x) {
                                check = false;
                            }
                        }
                        curr -= 2;
                        temp--;
                    }
                    if (check) {
                        ans++;
                    }
                    else 
                        looking = false;
                    start += 2;
                    curr = start;
                }
            }
        }
        printf("%d\n", ans);
    }
}