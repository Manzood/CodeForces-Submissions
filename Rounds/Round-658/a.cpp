#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		set <int> a;
		int ans = -1;
		int temp;
		for (int i=0; i<n; i++) {
			scanf("%d", &temp);
			a.insert(temp);
		}
		bool found = false;
		for (int i=0; i<m; i++) {
			scanf("%d", &temp);
			if (a.count(temp)) {
				found = true;
				ans = temp;
			}
		}
		if (found) {
			printf("YES\n");
			printf("1 %d\n", ans);
		}
		else
			printf("NO\n");
	}
}