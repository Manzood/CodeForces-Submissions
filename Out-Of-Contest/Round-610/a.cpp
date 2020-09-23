#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, r;
		scanf("%d%d%d%d", &a, &b, &c, &r);
		long long ans = b - a;
		// to the left, calculate distance to a from c, if its greater than r, great, otherwise pick the distance
		// then check if c is to the left of b, otherwise use a min operation again
		ans -= max(0, min(min(c-a, r), min(b-c, r)));
		ans -= max(0, min(min(b-c, r), min(c-a, r)));
		if (ans < 0) ans = 0;
		printf("%lld\n", ans);
	}
} 
