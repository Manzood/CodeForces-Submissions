#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		if (a > b) swap(a, b);
		// left side of radius
		int ans = max(a, min(b, c)) - min(b, max(c-r, a));
		ans += max(a, min(c+r, b)) - min(b, max(a, c));
		ans = b - a - ans; 
		printf("%d\n", ans);
	}
}	