#include<bits/stdc++.h>
using namespace std;

int main() {
    // This program prints one; if you want to count the number of occurances of each number, use a map instead

    set <int> a;
    for (int i = 0; i < 10; i++) {
        a.insert(5);
    }
    cout << a.count(5) << endl;
}
