#include "bits/stdc++.h"
using namespace std;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, l;
        scanf("%d%d", &n, &l);
        vector <int> temp(n);
        vector <double> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp[i]);
            a[i] = temp[i];
        }
        sort(a.begin(), a.end());
        double start = 0;
        double end = n-1;
        double startpos = 0;
        double endpos = l;
        double startspeed = 1, endspeed = 1;
        double ans = 0;
        while (start <= end) {
            double mtime = min((a[start] - startpos)/startspeed, (endpos - a[end])/endspeed);
            ans += mtime;
            startpos += startspeed*mtime; 
            endpos -= endspeed*mtime;
            if (a[start] - startpos > endpos - a[end]) {
                end--;
                endspeed++;
            }
            else if (a[start] - startpos < endpos - a[end]) {
                start++;
                startspeed++;
            }
            else {
                start++;
                startspeed++;
                end--;
                endspeed++;
            }
        }
        if (startpos < endpos) {
            double dist = endpos - startpos;
            double time = dist/(startspeed+endspeed);
            ans += time;
        }
        printf("%.12lf\n", ans);
    }
}