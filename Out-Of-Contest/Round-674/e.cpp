#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(3), b(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];
    int alice = 0, mi = 0;
    alice = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);  
    // bob = min(b[0], a[1]) + min(b[1], a[2]) + min(b[2], a[0]);  
    // use an optimal solution, get rid of the number of losses
    printf("%d %d\n", mi, alice);
}