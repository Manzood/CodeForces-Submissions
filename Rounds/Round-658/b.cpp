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
		bool first = true;
		bool found = false;
		for (int i=0; i<n; i++) {
			scanf("%d", &a[i]);
			if (found == false && i < n-1 && a[i] == 1) {
				first = !first;
			}
			if (a[i] > 1) {
				found = true;
			}
		}
		if (first)
			printf("First\n");
		else 
			printf("Second\n");
	}
}