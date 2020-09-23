#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

// alternate, faster solution: using a dsu to check if the components are connected
// this is basically tourist's solution, because the only requirement the problem really required was the implementation of a DSU
class dsu {
  public: 
    vector <int> p;
    vector <int> size;      
    int n;
    dsu (int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        size.resize(n, 1);
    }
    int parent(int x) {
        if (x == p[x]) return x;
        else return p[x] = parent(p[x]);
    }
    inline bool unite (int x, int y) {
        x = parent(x); y = parent(y);
        if (x != y) {
            if (size[x] > size[y]) 
                swap(x, y);
            p[x] = y;
            size[x] += size[y];
            return true;
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        string a, b;
        cin >> a >> b;
        dsu d(20);
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i] > b[i]) {
                ans = -1;
                break;
            }
            else {
                if (d.unite(a[i] - 'a', b[i] - 'a') == true) ans++;
            }
        }
        printf("%d\n", ans);
    }
}
