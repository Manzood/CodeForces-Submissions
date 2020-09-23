#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		vector <int> a(n);
		for (int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		vector <string> ans(n+1);
		for (int i=0; i<n+1; i++) {
			ans[i] = "";
			if (i == 0) {
				for (int j=0; j<200; j++) {
					ans[i] += "a";
				}
			}
			else {
				for (int j=0; j<200	; j++) {
					if (j < a[i-1])
						ans[i] += ans[i-1][j];
					else {
						if (ans[i-1][j] == 'a') ans[i] += 'b';
						else ans[i] += 'a';
					}
				}
			}
		}
		for (int i=0; i<ans.size(); i++) {
			cout << ans[i] << '\n';
		}
	}
}	
