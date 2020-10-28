#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

bool is_prime (int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        vector <int> row(n);
        row[0] = 1; 
        int sum = 1;
        for (int i = 1; i < n; i++) {
            row[i] = 4;
            sum += row[i];
        }
        while (!is_prime(sum)) {
            row[n-1] += 4;
            sum += 4;
        }
        int start = 0;
        for (int i = 0; i < n; i++) {
            int curr = start;
            for (int j = 0; j < n; j++) {
                if (curr == n) curr = 0;
                printf("%d ", row[curr]);
                curr++;
            }
            printf("\n");
            start++;
        }
    }
}
