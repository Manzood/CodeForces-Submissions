#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
const int mx = (int)1e9;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector <pair<int, int>> robbers(n);
    // vector <pair<int, int>> lights(m);
    vector <int> lightshor(m);
    vector <int> lightsver(m);
    int maxvert = 0;
    int maxhor = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &robbers[i].first, &robbers[i].second);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &lightshor[i], &lightsver[i]);
        maxvert = max(maxvert, lightsver[i]);
        maxhor = max(maxhor, lightshor[i]);
    }
    sort(lightshor.begin(), lightshor.end());
    sort(lightsver.begin(), lightsver.end());
    // make dp graph, of sorts
    vector <int> ver(maxhor+2, 0);
    vector <int> hor(maxvert+2, 0);
    int start = 0;
    for (int i = 0; i <= maxhor; i++) {
        if (i == lightsver[start]) {
            if (i > 0) hor[i] = max(hor[i-1], lightsver[start]);
            else hor[i] = lightsver[start];
            start++;
        }
        else {
            if (i > 0) hor[i] = max(hor[i], hor[i-1]);
        }
    }
    start = 0;
    for (int i = 0; i <= maxvert; i++) {
        if (i == lightshor[start]) {
            if (i > 0) ver[i] = max(ver[i-1], lightshor[start]);
            else ver[i] = lightshor[start];
            start++;
        }
        else {
            if (i > 0) ver[i] = max(ver[i], ver[i-1]);
        }
    }
    for (int i = 0; i <= maxvert; i++) {
        debug(hor[i]);
    }
    // ver should store the distance to closest horizontal free state
    // for each robber, check the horizontal and vertical minimum
    int ans = mx;
    for (int i = 0; i < n; i++) {
        // if it is greater than zero?
        int dist1 = mx;
        int dist2 = mx;
        if (hor[robbers[i].second] > robbers[i].first) dist1 = hor[robbers[i].second] - robbers[i].first;
        if (ver[robbers[i].first] > robbers[i].second) dist2 = ver[robbers[i].first] - robbers[i].second;
        int dist = min(dist1, dist2);
        debug(robbers[i].second);
        debug(hor[robbers[i].second]);
        // int dist = min(hor[robbers[i].first] - robbers[i].second, ver[robbers[i].second] - robbers[i].first);
        ans = min(dist+1, ans);
    }
    printf("%d\n", ans);
}