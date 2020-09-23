#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return rand() % (b-a+1) + a;
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int t;
    t = rand(1, 3);
    cout << t << endl;
    while (t--) {
        int n;
        n = rand(2, 8);
        int a, b;
        int da, db;
        a = rand(1, n);
        b = rand(1, n);
        da = rand(1, n-1);
        db = rand(1, n-1);
        cout << n << " " << a << " " << b << " " << da << " " << db << endl;     
        set <int> prev;
        for (int i = 0; i < n-1; i++) {
            int u, v;
            u = rand(1, n);
            while ((int)prev.size() < n && prev.count(u)) {
                u = rand(1, n);
            }
            prev.insert(u);
            v = rand(1, n);
            prev.insert(v);
            cout << u << " " << v << " "  << endl;
        }
    }
}