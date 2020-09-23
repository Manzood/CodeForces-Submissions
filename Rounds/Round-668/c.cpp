#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        string s;
        cin >> s;
        string comp;
        bool possible = true;
        int ones = 0;
        int zeroes = 0;
        for (int i = 0; i < k; i++) {
            comp += s[i];
            if (s[i] == '1') 
                ones++;
            else if (s[i] == '0') 
                zeroes++;
        }
        int start = 0;
        for (int i = k; i < n; i++) {
            if (i % k == 0) {
                start = 0;
            }
            if (s[i] != '?') {
                if (s[i] != comp[start]) {
                    if (comp[start] == '?') {
                        comp[start] = s[i];
                        if (s[i] == '1') 
                            ones++;
                        else if (s[i] == '0')
                            zeroes++;
                    }
                    else {
                        possible = false;
                    }
                }
            }
            start++;
        }
        if (ones > k/2 || zeroes > k/2) 
            possible = false;
        if (possible) 
            printf("YES\n");
        else 
            printf("NO\n");
    }
}