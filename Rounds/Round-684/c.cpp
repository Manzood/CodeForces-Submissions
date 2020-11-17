#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

vector <vector <int>> ans;

void make_three (int x, int y, vector <vector <int>> &a) {
    bool found = false;
    vector <int> temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[x+i][y+j] == 0) {
                if (!found) found = true;
                else {
                    a[i+x][j+y] = !a[i+x][j+y];
                    temp.push_back(i+x);
                    temp.push_back(j+y);
                }
            } else {
                a[i+x][j+y] = !a[i+x][j+y];
                temp.push_back(i+x);
                temp.push_back(j+y);
            }
        }
    }
    ans.push_back(temp);
}

void make_two (int x, int y, vector <vector <int>> &a) {
    vector <int> temp;
    int xmark1 = -1, ymark1 = -1, xmark2 = -1, ymark2 = -1;
    for (int i = 0; i < 2 && (xmark1 == -1 || xmark2 == -1); i++) {
        for (int j = 0; j < 2 && (xmark1 == -1 || xmark2 == -1); j++) {
            if (a[i+x][j+y] == 1) {
                if (xmark1 != -1) {
                    xmark2 = i+x;
                    ymark2 = j+y;
                } else {
                    xmark1 = i+x;
                    ymark1 = j+y;
                }
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i+x == xmark1 && j+y == ymark1) continue;
            temp.push_back(i+x);
            temp.push_back(j+y);
            a[i+x][j+y] = !a[i+x][j+y];
        }
    }
    ans.push_back(temp);
    temp.resize(0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i+x == xmark2 && j+y == ymark2) continue;
            temp.push_back(i+x);
            temp.push_back(j+y);
            a[i+x][j+y] = !a[i+x][j+y];
        }
    }
    ans.push_back(temp);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ans.resize(0);
        int n, m;
        scanf("%d%d", &n, &m);
        vector <vector <int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i].resize(m);
            string s;
            cin >> s;
            for (int j = 0; j < (int)s.size(); j++) {
                a[i][j] = s[j] - '0';
            }
        }
        for (int i = 0; i < n-1; i+=2) {
            for (int j = 0; j < m-1; j+=2) {
                if (i == n-3 && j == m-3) {
                    if (a[n-1][m-1] == 1) {
                        vector <int> temp;
                        int startx = n-2, starty = m-2;
                        for (int x = 0; x < 2; x++) {
                            for (int y = 0; y < 2; y++) {
                                if (x == 0 && y == 0) continue;
                                temp.push_back(startx+x);
                                temp.push_back(starty+y);
                                a[startx+x][starty+y] = !a[startx+x][starty+y];
                            }
                        }
                        ans.push_back(temp);
                    }
                }
                if (m % 2 == 1 && j == m-3) {
                    // check the last two, flip them
                    if (a[i][m-1] + a[i+1][m-1] == 1) {
                        vector <int> temp;
                        for (int x = i; x < i+2; x++) {
                            for (int y = m-2; y < m; y++) {
                                if (y == m-1 && a[x][y] == 0) continue;
                                temp.push_back(x);
                                temp.push_back(y);
                                a[x][y] = !a[x][y];
                            }
                        }
                        ans.push_back(temp);
                    } else if (a[i][m-1] + a[i+1][m-1] == 2) {
                        int startx = i;
                        int starty = m-2;
                        vector <int> temp;
                        for (int x = 0; x < 2; x++) {
                            for (int y = 0; y < 2; y++) {
                                if (x == 0 && y == 1) continue;
                                temp.push_back(startx+x);
                                temp.push_back(starty+y);
                                a[startx+x][starty+y] = !a[startx+x][starty+y];
                            }
                        }
                        ans.push_back(temp);
                        temp.resize(0);
                        for (int x = 0; x < 2; x++) {
                            for (int y = 0; y < 2; y++) {
                                if (x == 1 && y == 1) continue;
                                temp.push_back(startx+x);
                                temp.push_back(starty+y);
                                a[startx+x][starty+y] = !a[startx+x][starty+y];
                            }
                        }
                        ans.push_back(temp);
                    }
                } if (n % 2 == 1 && i == n-3) {
                    if (a[n-1][j] + a[n-1][j+1] == 1) {
                        vector <int> temp;
                        for (int x = n-2; x < n; x++) {
                            for (int y = j; y < j+2; y++) {
                                if (x == n-1 && a[x][y] == 0) continue;
                                temp.push_back(x);
                                temp.push_back(y);
                                a[x][y] = !a[x][y];
                            }
                        }
                        ans.push_back(temp);
                    } else if (a[n-1][j] + a[n-1][j+1] == 2) {
                        int startx = n-2;
                        int starty = j;
                        vector <int> temp;
                        for (int x = 0; x < 2; x++) {
                            for (int y = 0; y < 2; y++) {
                                if (x == 1 && y == 0) continue;
                                temp.push_back(startx+x);
                                temp.push_back(starty+y);
                                a[startx+x][starty+y] = !a[startx+x][starty+y];
                            }
                        }
                        ans.push_back(temp);
                        temp.resize(0);
                        for (int x = 0; x < 2; x++) {
                            for (int y = 0; y < 2; y++) {
                                if (x == 1 && y == 1) continue;
                                temp.push_back(startx+x);
                                temp.push_back(starty+y);
                                a[startx+x][starty+y] = !a[startx+x][starty+y];
                            }
                        }
                        ans.push_back(temp);
                    }
                }

                int sum = 0;
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        sum += a[i+x][j+y];
                    }
                }
                if (sum == 1) {
                    make_three (i, j, a);
                    make_two (i, j, a);
                } else if (sum == 2) {
                    make_two (i, j, a);
                    // for (int x = 0; x < n; x++) {
                    //     for (int y = 0; y < m; y++) {
                    //         printf("%d", a[x][y]);
                    //     }
                    //     printf("\n");
                    // }
                } else if (sum == 3) {
                    vector <int> temp;
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 2; y++) {
                            if (a[i+x][j+y] == 1) {
                                temp.push_back(i+x);
                                temp.push_back(j+y);
                                a[i+x][j+y] = !a[i+x][j+y];
                            }
                        }
                    }
                    ans.push_back(temp);
                } else if (sum == 4) {
                    vector <int> temp;
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 2; y++) {
                            if (x != 1 || y != 1) {
                                temp.push_back(i+x);
                                temp.push_back(j+y);
                                a[i+x][j+y] = !a[i+x][j+y];
                            }
                        }
                    }
                    ans.push_back(temp);
                    make_three(i, j, a);
                    make_two(i, j, a);
                }
            }
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < (int)ans.size(); i++) {
            for (int j = 0; j < (int)ans[i].size(); j++) {
                printf("%d ", ans[i][j] + 1);
            } 
            printf("\n");
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         printf("%d", a[i][j]);
        //     }
        //     printf("\n");
        // }
    }
}