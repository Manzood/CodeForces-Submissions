#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector <vector <char>> a(n);
        vector <vector <int>> score(n);
        vector <vector <int>> mark(n);
        for (int i = 0; i < n; i++) {
            score[i].resize(n, 0);
            a[i].resize(n);
            mark[i].resize(n, 0);
            for (int j = 0; j < n; j++) {
                char temp; cin >> temp;
                a[i][j] = temp;
            }
        }

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[j][i] == 'X') {
                    cnt++;
                } else {
                    cnt = 0;
                }
                if (cnt == 3) {
                    for (int temp = 0; temp < 3; temp++) {
                        // score[j-temp][i]++;
                        mark[j-temp][i] = 1;
                    }
                    // a[j-1][i] = 'O';
                    cnt = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'X') {
                    cnt++;
                } else {
                    cnt = 0;
                }
                if (cnt == 3) {
                    for (int temp = 0; temp < 3; temp++) {
                        // score[i][j-temp]++;
                        mark[i][j-temp] = 1;
                    }
                    // a[i][j-1] = 'O';
                    cnt = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0) score[i][j] += mark[i-1][j];
                if (i + 1 < n) score[i][j] += mark[i+1][j];
                if (j - 1 >= 0) score[i][j] += mark[i][j-1];
                if (j + 1 < n) score[i][j] += mark[i][j+1];
                if (i+1 < n && mark[i+1][j] && i-1 && mark[i-1][j]) score[i][j]--;
                if (j+1 < n&& mark[i][j+1] && j-1 && mark[i][j-1]) score[i][j]--;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", score[i][j]);
                if (a[i][j] == 'X' && score[i][j] > 1) {
                    score[i][j] = 0;
                    a[i][j] = 'O';
                }
            }   
            printf("\n");
        }

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[j][i] == 'X') {
                    cnt++;
                } else {
                    cnt = 0;
                }
                if (cnt == 3) {
                    a[j-1][i] = 'O';
                    cnt = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'X') {
                    cnt++;
                } else {
                    cnt = 0;
                }
                if (cnt == 3) {
                    a[i][j-1] = 'O';
                    cnt = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", a[i][j]);
            }
            printf("\n");
        }
    }
}
